#pragma once
#ifndef  __FightGame__Table__
#define __FightGame__Table__
#include"Tile.h"
class Table:
	public Tile
{
public:
	Table(Entity* e) { _entity = e;  this->_HighLightSign = new HighLightSign(this->getEntity()->getPosition()); }
	~Table();
	 Entity* getEntity() { return this->_entity;}
	 void setEntity(Entity &entity) { this->_entity = &entity; }
};

#endif
