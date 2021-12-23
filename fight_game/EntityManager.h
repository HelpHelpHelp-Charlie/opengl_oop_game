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
	int addNewEntity(IngredientType type);
	void update();


	static EntityManager& getEntityManager();
	static void destroyEntityManager();
};


#endif