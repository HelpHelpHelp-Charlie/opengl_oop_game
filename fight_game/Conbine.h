#pragma once
#ifndef __FightGame__Combine__
#define __FightGame__Combine__
#include"AbstractInteraction.h"
#include "Tile.h"
class Combine :
	public AbstractInteraction {
private:
	EntityManager *_entityManager;
public:
	Combine() {
		this->enable = false;
		this->_entityManager = &EntityManager::getEntityManager();
	};
	bool CombineOnTile(bool trigger, Player* player, Tile* tile, bool call);
};
#endif