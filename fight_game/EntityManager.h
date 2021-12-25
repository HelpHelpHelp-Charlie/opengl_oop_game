#pragma once
#ifndef  __FightGame__EntityManager__
#define __FightGame__EntityManager__
#include"ConcreteIngredient.h"
#include<vector>

class EntityManager {
private:
	std::vector<Entity *>* _entityArr;
	std::vector<int>_IDarray;
public:
	EntityManager();
	std::vector<Entity *>* getEntityArr();
	std::vector<int> getIDarray();
	int addNewEntity(IngredientType type);
	void update();
	void removeEntity(int ID);
	void show();
	static EntityManager& getEntityManager();
	static void destroyEntityManager();
};


#endif