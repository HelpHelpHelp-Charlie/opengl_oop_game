#pragma once
#ifndef  __FightGame__EntityManager__
#define __FightGame__EntityManager__
#include"ConcreteIngredient.h"
#include<vector>

class EntityManager {
private:
	std::vector<Entity *>* _entityArr;
public:
	EntityManager();
	std::vector<Entity *>* getEntityArr();
	void addNewEntity(IngredientType type,Vec2 pos);
};


#endif