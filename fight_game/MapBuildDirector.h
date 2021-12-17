#pragma once

#ifndef  __FightGame__MapBuildDirector__
#define __FightGame__MapBuildDirector__
#include"Tile.h"
#include"TileBuilder.h"

#include"MEATBOX.h"
#include"Stove.h"
#include"Table.h"
class MapBuildDirector {
	Tile *_tile;
public:

	Tile* Create(TileBuilder *builder, Vec2 pos) {

		this->_tile = new Tile(builder->getResult(pos));
		cout << "ddddddlll";
		return this->_tile;
	}
};

#endif