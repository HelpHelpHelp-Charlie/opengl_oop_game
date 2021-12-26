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
		default:
			break;
		}
	

		
	}	

}
