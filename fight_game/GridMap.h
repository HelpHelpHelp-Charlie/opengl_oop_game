#pragma once

#ifndef  __FightGame__GridMap__
#define __FightGame__GridMap__

#include"Entity.h"
#include"MapBuildDirector.h"
#include<vector>
#include"StoveBuilder.h"
#include"MeatBoxBuilder.h"
#include"TableBuilder.h"
class GridMap {
private:
	void readFile(const char * filename);
public:
	std::vector<Tile*>* _tileArray;
	std::vector<Entity*>*_entityArray;
	void drawMap(double deltaTime);
	vector<Vec4*> *_mapinfo;
	GridMap(const char* filename);
};
#endif