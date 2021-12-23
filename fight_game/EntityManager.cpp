#include "EntityManager.h"

EntityManager::EntityManager()
{
	this->_entityArr = new std::vector<Entity *>;
}

std::vector<Entity*>* EntityManager::getEntityArr()
{
	return this->_entityArr;
}

void EntityManager::addNewEntity(IngredientType type, Vec2 pos)
{
	switch (type) {
	case IngredientType::PLATE:break;
	case IngredientType::MEAT:
		Meat* meat=new Meat;
		this->_entityArr->push_back(meat);
		meat->setID(this->_entityArr->size() - 1);
		break;
	}
}

