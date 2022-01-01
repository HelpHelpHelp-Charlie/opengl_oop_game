#pragma once
#ifndef __FightGame__PlaceThing__
#define __FightGame__PlaceThing__
#include"AbstractInteraction.h"
#include "Tile.h"
class PlaceThing :
	public AbstractInteraction {
private:
	EntityManager *_entityManager;
public:
	PlaceThing() {
		this->enable = false;
		this->_entityManager = &EntityManager::getEntityManager();
	};
	bool Place(bool trigger, Player* player, Tile* tile, bool call);
};
#endif