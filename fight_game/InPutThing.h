#pragma once
#ifndef __FightGame__InPutThing__
#define __FightGame__InPutThing__
#include"AbstractInteraction.h"
#include "Tile.h"
class InPutThing :
	public AbstractInteraction {
private:
	EntityManager *_entityManager;
	bool _onlyFor =false;
	IngredientType _onlyForType;
	
public:

	InPutThing() {
		this->_entityManager = &EntityManager::getEntityManager();
	};
	InPutThing(IngredientType OnlyForType) {
		this->_entityManager = &EntityManager::getEntityManager();
		this->_onlyForType = OnlyForType;
		this->_onlyFor = true;
	};
	bool Input(bool trigger, Player* player, Tile* tile);
};
#endif