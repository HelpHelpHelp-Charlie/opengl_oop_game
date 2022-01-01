#pragma once
#ifndef __FightGame__Combine__
#define __FightGame__Combine__
#include"AbstractInteraction.h"
#include "Tile.h"
#include"machingSystem.h"
class Combine :
	public AbstractInteraction {
private:
	EntityManager *_entityManager;
	MachingSystem *_machingSystem;
public:
	Combine() {
		this->enable = false;
		this->_entityManager = &EntityManager::getEntityManager();
		this->_machingSystem = &MachingSystem::getMachingSystem();
	};
	bool CombineOnTile(bool trigger, Player* player, Tile* tile);
};
#endif