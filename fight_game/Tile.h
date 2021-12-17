#pragma once
#ifndef  __FightGame__Tile__
#define __FightGame__Tile__
#include"collision2D.h"
#include"Entity.h"

enum TileType {
	TABLE,STOVE,MEATBOX,NumberOfAnimalItem
};


class  Tile {
public:
	Tile(Entity* e) :_entity(e) {}
	Entity* getEntity() { return this->_entity; }
	void setEntity(Entity &entity) { this->_entity = &entity; }
protected:
	Entity *_entity;
};

#endif