#pragma once
#ifndef __FightGame__grabFromBox__
#define __FightGame__grabFromBox__
#include"AbstractInteraction.h"

class GrabFromBox :
	public AbstractInteraction {
private:
	EntityManager *_entityManager;
public:
	GrabFromBox() {
		this->_entityManager = &EntityManager::getEntityManager();
		this->enable = true;
	};
	
	bool grab(bool trigger,Player* player, IngredientType type);



};
#endif // !__FightGame__HighLightSign__