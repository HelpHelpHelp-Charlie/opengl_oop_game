#pragma once

#ifndef  __FightGame__MapBuildDirector__
#define __FightGame__MapBuildDirector__
#include"Tile.h"
#include"TileBuilder.h"
#include"Trashcan.h"
#include"MEATBOX.h"
#include"Stove.h"
#include"Table.h"
#include"BunBox.h"
#include"Former.h"
#include"PlateBox.h"
class MapBuildDirector {
	//Tile *_tile;
public:

	Tile* Create(TileBuilder *builder, Vec2 pos) {
		Tile *_tile = builder->getResult(pos);
		return _tile;
	}
};

#endif