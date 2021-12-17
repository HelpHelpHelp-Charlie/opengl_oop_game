#pragma once
#ifndef  __FightGame__MeatBox__
#define __FightGame__MeatBox__
#include"Tile.h"
class MeatBox :
	public Tile
{
public:
	MeatBox(Entity* e) { _entity = e; }
	//
	~MeatBox();
	 Entity* getEntity() { return this->_entity; }
	 void setEntity(Entity &entity) { this->_entity = &entity; }
	
};

#endif

