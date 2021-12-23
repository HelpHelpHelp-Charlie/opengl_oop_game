#include "EntityManager.h"

EntityManager::EntityManager()
{
	if (this->_entityArr == NULL) { this->_entityArr = new std::vector<Entity *>; }
}

std::vector<Entity*>* EntityManager::getEntityArr()
{
	return this->_entityArr;
}

int EntityManager::addNewEntity(IngredientType type)
{
	switch (type) {
		//	case IngredientType::PLATE:break;
	case IngredientType::MEAT:
		Meat* meat = new Meat;
		this->_entityArr->push_back(meat);
		meat->setID(this->_entityArr->size());
		//cout<<"sss" << this->_entityArr->size() << endl;
		return this->_entityArr->size()-1;
		break;
	}
}

void EntityManager::update()
{
	for (std::vector<Entity*>::iterator iterator = this->_entityArr->begin(); iterator != this->_entityArr->end(); iterator++) {
		Entity* entity = *iterator;
		//tile->update(player->getAtGridTile(), player->getEyeVector());
		entity->update();
	}
}

EntityManager & EntityManager::getEntityManager()
{
	static EntityManager *entityManager = NULL;

	if (entityManager == NULL) {
		entityManager = new EntityManager();
		
	}

	return *entityManager;
}

void EntityManager::destroyEntityManager()
{

	EntityManager *entityManager = &getEntityManager();
	delete entityManager;
}


