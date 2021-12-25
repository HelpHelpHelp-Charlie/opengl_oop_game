#pragma once
#ifndef __FightGame__TakeThing__
#define __FightGame__TakeThing__
#include"AbstractInteraction.h"
#include "Tile.h"
class TakeThing :
	public AbstractInteraction {
private:
	EntityManager *_entityManager;
public:
	TakeThing() {
		this->enable = false;
		this->_entityManager = &EntityManager::getEntityManager();
	};
	bool Take(bool trigger, Player* player, Tile* tile, bool call);
};
#endif