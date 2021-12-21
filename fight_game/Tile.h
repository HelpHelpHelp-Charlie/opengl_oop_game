#pragma once
#ifndef  __FightGame__Tile__
#define __FightGame__Tile__
#include"collision2D.h"
#include"Entity.h"
#include"HighLightSign.h"
enum TileType {
	TABLE,STOVE,MEATBOX,NumberOfAnimalItem
};


class  Tile {
public:
	/*Tile(Entity* e) { _entity = e; }
	Entity* getEntity() { return this->_entity; }
	void setEntity(Entity &entity) { this->_entity = &entity; }*/

	// Tile(Entity* e) :_entity(e) {}
	virtual Entity* getEntity() = 0;
	Entity* getHighLightSignEntity() {return this->_HighLightSign->getEntity();};
	virtual void setEntity(Entity &entity) = 0;
	void update(Vec2 PlayerPos, Vec2 playerLookAt) {
		this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getEntity()->getPosition(),PlayerPos,playerLookAt));
	}

protected:

	HighLightSign *_HighLightSign;
	Entity *_entity;

};

#endif