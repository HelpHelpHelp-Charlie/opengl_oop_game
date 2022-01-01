#include "GridMap.h"
#include"Vec8.h"


void GridMap::readFile(const char * filename)
{
	FILE* fp = nullptr;
	const int bufferlen = 255;
	char line[bufferlen];
	fopen_s(&fp, filename, "r");
	if (fp == nullptr)
	{
		printf("erorr in reading animation file \n");
	}
	else
	{
		_mapinfo = new vector<Vec4*>;

		while (fgets(line, bufferlen, fp))
		{
			vector<int> result;

			stringstream ss(line);
			string token;
			while (getline(ss, token, ','))
			{
				result.push_back(stoi(token));
			}


			Vec4 *info = new Vec4(result[0], result[1], result[2], result[3]);
			_mapinfo->push_back(info);
		}
	}
	//frames_count = (int)_frames->size();
	fclose(fp);
}



void GridMap::drawMap(double deltaTime)
{	
	if (this->_backGround->getAnimator() != NULL) {
		glLoadIdentity();
		glTranslatef(this->_backGround->getPosition().x, this->_backGround->getPosition().y, 0);
		this->_backGround->getAnimator()->play(this->_backGround->getNowAnimate_No(), deltaTime);
	}
	for (std::vector<Tile*>::iterator iterator = this->_tileArray->begin(); iterator != this->_tileArray->end(); iterator++) {
		Tile *tile = *iterator;
		if (tile->getSprite()->getAnimator() != NULL) {
			glLoadIdentity();
			glTranslatef(tile->getSprite()->getPosition().x, tile->getSprite()->getPosition().y, 0);
			//glRotatef(sprite->getRotation(), 0.0f, 0.0f, 1.0f);
			//glScalef(sprite->getScale().x, sprite->getScale().y, 1);		


			tile->getSprite()->getAnimator()->play(tile->getSprite()->getNowAnimate_No(), deltaTime);
			tile->getHighLightSignSprite()->getAnimator()->play(tile->getHighLightSignSprite()->getNowAnimate_No(), deltaTime);
			

			glLoadIdentity();
			glTranslatef(tile->getSprite()->getPosition().x, tile->getSprite()->getPosition().y-20, 0);
			if (tile->getProgressBarSprite()!=nullptr)tile->getProgressBarSprite()->getAnimator()->play(tile->getProgressBarSprite()->getNowAnimate_No(), deltaTime);

		}
	}

}

Vec2 GridMap::getGridLocationInMap(Vec2 loc)
{
	return Vec2(int(loc.x/this->tileWidth), int(loc.y / this->tileWidth));
}



void GridMap::update(Player* player)
{
	for (std::vector<Tile*>::iterator iterator = this->_tileArray->begin(); iterator != this->_tileArray->end(); iterator++) {
		Tile* tile = *iterator;
		//tile->update(player->getAtGridTile(), player->getEyeVector());
		tile->update(player);
	}
}


GridMap::GridMap(const char * filename)
{
	readFile(filename);
	MapBuildDirector* mapBuildDirector = new MapBuildDirector();
	StoveBuilder* stoveBuiler = new StoveBuilder();
	MeatBoxBuilder * meatBoxBuilder = new MeatBoxBuilder();
	TableBuilder* tableBuilder = new TableBuilder();
	TrashcanBuilder* trashcanBuilder = new TrashcanBuilder();
	BunBoxBuilder* bunBoxBuilder = new BunBoxBuilder();
	FormerBuilder* formerBuilder = new FormerBuilder();
	PlateBoxBuilder* plateBoxBuilder = new PlateBoxBuilder();
	PickUpBarBuilder* pickUpBarBuilder = new PickUpBarBuilder();
	this->_tileArray = new vector<Tile*>;
	for (std::vector<Vec4 *>::iterator iterator = _mapinfo->begin(); iterator != _mapinfo->end(); iterator++) {

		Vec4 *info = *iterator;
		Vec2 pos(info->y*this->tileWidth, info->z*this->tileWidth);

		//Tile *tilevvv = new Tile();
		//tilevvv = mapBuildDirector->Create(stoveBuiler, pos);
	
	
		switch (int(info->x)) {
		case TileType::MEATBOX:
			this->_tileArray->push_back(mapBuildDirector->Create(meatBoxBuilder, pos));
			break;
		case TileType::STOVE:
			this->_tileArray->push_back(mapBuildDirector->Create(stoveBuiler, pos));
			break;
		case TileType::TABLE:
			this->_tileArray->push_back(mapBuildDirector->Create(tableBuilder, pos));
			break;
		case TileType::TRASHCAN:
			this->_tileArray->push_back(mapBuildDirector->Create(trashcanBuilder, pos));
			break;
		case TileType::BUNBOX:
			this->_tileArray->push_back(mapBuildDirector->Create(bunBoxBuilder, pos));
			break;
		case TileType::FORMER:
			this->_tileArray->push_back(mapBuildDirector->Create(formerBuilder, pos));
			break;
		case TileType::PLATEBOX:
			this->_tileArray->push_back(mapBuildDirector->Create(plateBoxBuilder, pos));
			break;
		case TileType::PICKUPBAR:
			this->_tileArray->push_back(mapBuildDirector->Create(pickUpBarBuilder, pos));
			break;
		default:
			break;
		}
	

		
	}	

	makeBackGround();

}

void GridMap::makeBackGround()
{
	std::vector<Texture *>*_textureArray = new std::vector<Texture *>();
	Texture *Texture_Shark = new Texture("back.tga", Vec4( 1600,1000, 3,1));
	_textureArray->push_back(Texture_Shark);

	std::vector<Animator *>*_animatorArray = new std::vector<Animator *>();

	Animator *player = new Animator();
	_animatorArray->push_back(player);


	Animation2D *a = new Animation2D("back.txt", 100);
	_animatorArray->at(0)->_animation2DArray->push_back(a);


	int animation2DCounter = 0;
	std::vector<Vec4*> *normalizeFrames = new std::vector<Vec4*>();
	for (std::vector<Animation2D*>::iterator animatorIterator = _animatorArray->at(0)->_animation2DArray->begin();
		animatorIterator != _animatorArray->at(0)->_animation2DArray->end(); animatorIterator++) {

		normalizeFrames = _animatorArray->at(0)->_animation2DArray->at(animation2DCounter)->getNormallizeFramesArray(_textureArray->at(0)->getTextureCutSetting());


		int normalizeFrameCounter = 0;
		std::vector<VertexBuffer *>* _vertexBufferArray = new std::vector<VertexBuffer *>();
		for (std::vector<Vec4*>::iterator iterator = normalizeFrames->begin(); iterator != normalizeFrames->end(); iterator++) {
			VertexData vertices[4] = {
				{ { 0,0,0 },{ normalizeFrames->at(normalizeFrameCounter)->x,normalizeFrames->at(normalizeFrameCounter)->y } },
				{ { 1600,0,0 },{ normalizeFrames->at(normalizeFrameCounter)->x + normalizeFrames->at(normalizeFrameCounter)->z,normalizeFrames->at(normalizeFrameCounter)->y } },
				{ { 1600,1000,0 },{ normalizeFrames->at(normalizeFrameCounter)->x + normalizeFrames->at(normalizeFrameCounter)->z,normalizeFrames->at(normalizeFrameCounter)->y - normalizeFrames->at(normalizeFrameCounter)->w } },
				{ { 0,1000,0 },{ normalizeFrames->at(normalizeFrameCounter)->x, normalizeFrames->at(normalizeFrameCounter)->y - normalizeFrames->at(normalizeFrameCounter)->w } }
			};
			normalizeFrameCounter++;
			VertexBuffer *vertexBuffer = new VertexBuffer(
				vertices,
				sizeof(vertices),
				GL_QUADS,
				4,
				sizeof(VertexData),
				_textureArray->at(0),
				(GLvoid*)offsetof(VertexData, positionCoordinates),
				(GLvoid*)offsetof(VertexData, textureCoordinates));
			_vertexBufferArray->push_back(vertexBuffer);
		}

		_animatorArray->at(0)->_animation2DArray->at(animation2DCounter)->setvertexBufferArray(_vertexBufferArray);
		animation2DCounter++;
	}

	this->_backGround = new Sprite(_animatorArray->at(0), Vec2(0,0));
}
