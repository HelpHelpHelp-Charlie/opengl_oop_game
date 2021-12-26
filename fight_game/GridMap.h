#pragma once

#ifndef  __FightGame__GridMap__
#define __FightGame__GridMap__

#include"Sprite.h"
#include"MapBuildDirector.h"
#include<vector>
#include"StoveBuilder.h"
#include"MeatBoxBuilder.h"
#include"TableBuilder.h"
#include"TrashcanBuilder.h"
#include"FormerBuilder.h"
#include"BunBoxBuilder.h"
class Player;

class GridMap {
private:
	void readFile(const char * filename);

public:
	const int mapWidth = 10;
	const int mapHight = 6;
	const int tileWidth = 150;
	std::vector<Tile*>* _tileArray;
	std::vector<Sprite*>*_spriteHighLightSignArray;
	void drawMap(double deltaTime);
	vector<Vec4*> *_mapinfo;
		
	Vec2 getGridLocationInMap(Vec2 loc);
	//void update(Vec2 PlayerPos, Vec2 playerLookAt);
	void update(Player* player);
	GridMap(const char* filename);
	
};
#endif