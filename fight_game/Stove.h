#pragma once
#ifndef  __FightGame__Stove__
#define __FightGame__Stove__
#include"Tile.h"
class Stove :
	public Tile
{
public :
	Stove(Entity* e) { _entity = e; this->_HighLightSign = new HighLightSign(this->getEntity()->getPosition()); }
	~Stove();
	 Entity* getEntity() { return this->_entity;}
	 void setEntity(Entity &entity) { this->_entity = &entity; }
};

#endif