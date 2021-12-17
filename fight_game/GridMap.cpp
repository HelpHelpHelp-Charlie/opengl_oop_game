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
		if (tile->getEntity()->getAnimator() != NULL) {
			glLoadIdentity();
			glTranslatef(tile->getEntity()->getPosition().x, tile->getEntity()->getPosition().y, 0);
			//glRotatef(entity->getRotation(), 0.0f, 0.0f, 1.0f);
			//glScalef(entity->getScale().x, entity->getScale().y, 1);		

			//cout << "getNowAnimate_No= " << tile->getEntity()->getNowAnimate_No() << endl;
			tile->getEntity()->getAnimator()->play(tile->getEntity()->getNowAnimate_No(), deltaTime);
		}
	}
}

GridMap::GridMap(const char * filename)
{
	readFile(filename);
	MapBuildDirector* mapBuildDirector = new MapBuildDirector();
	StoveBuilder* stoveBuiler = new StoveBuilder();
	MeatBoxBuilder * meatBoxBuilder = new MeatBoxBuilder();
	//TableBuilder* tableBuilder = new TableBuilder();
	//cout << "shit like";
	this->_tileArray = new vector<Tile*>;
	for (std::vector<Vec4 *>::iterator iterator = _mapinfo->begin(); iterator != _mapinfo->end(); iterator++) {

		Vec4 *info = *iterator;
		Vec2 pos(info->y, info->z);

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
		//	this->_tileArray->push_back(mapBuildDirector->Create(tableBuilder, pos));
			break;
		default:
			break;
			//cout << "shit like" << endl;
		}
	

		
		//cout << "abc:" << this->_tileArray->at(0)->getEntity()<<" "<< this->_tileArray->at(0)->getEntity()->getAnimator()->_animation2DArray;// ->getNowAnimate_No();
		//this->_tileArray->at(0)->getEntity()->setNowAnimate_No(0);
		//cout << "def:" << this->_tileArray->at(0)->getEntity();//->getNowAnimate_No();
			//cout << "abc:" << tilevvv.getEntity() << " " << tilevvv.getEntity()->getAnimator()->_animation2DArray;

	}	
	int i = 0;
	this->_entityArray = new std::vector<Entity*>();
		for (std::vector<Tile*>::iterator iterator = this->_tileArray->begin(); iterator != this->_tileArray->end(); iterator++) {
			this->_entityArray->push_back(this->_tileArray->at(i)->getEntity());
			cout <<"fffpp"<< i<<endl;
			i++;
		}
}
