#include "EntityManager.h"

EntityManager::EntityManager()
{
	if (this->_entityArr == NULL) { this->_entityArr = new std::vector<Entity *>; }
}

std::vector<Entity*>* EntityManager::getEntityArr()
{
	return this->_entityArr;
}

std::vector<int> EntityManager::getIDarray()
{
	return this->_IDarray;
}

int EntityManager::addNewEntity(IngredientType type)
{
	switch (type) {
		//	case IngredientType::PLATE:break;
	case IngredientType::MEAT: {
		Meat* meat = new Meat;
		this->_entityArr->push_back(meat);
		break;
	}
	case IngredientType::BUN: {
		Bun* bun = new Bun;
		this->_entityArr->push_back(bun);
		break;
	}
	case IngredientType::RAWPATTIES: {
		RawPatties* rawPatties = new RawPatties;
		this->_entityArr->push_back(rawPatties);
		break;
	}
	case IngredientType::COOKEDPATTIES: {
		CookedPatties* cookedPatties = new CookedPatties;
		this->_entityArr->push_back(cookedPatties);
		break;
	}
	case IngredientType::PLATE: {
		Plate* plate = new Plate;
		this->_entityArr->push_back(plate);
		break;
	}
	case IngredientType::BUGER: {
		Buger* buger = new Buger;
		this->_entityArr->push_back(buger);
		break;
	}
	case IngredientType::PLATE_BUGER: {
		Plate_Buger* buger = new Plate_Buger;
		this->_entityArr->push_back(buger);
		break;
	}
	case IngredientType::PLATE_BUN: {
		Plate_Bun* buger = new Plate_Bun;
		this->_entityArr->push_back(buger);
		break;
	}
	case IngredientType::PLATE_PATTIES: {
		Plate_Patties* buger = new Plate_Patties;
		this->_entityArr->push_back(buger);
		break;
	}

	
	}
	this->_IDarray.push_back(_entityArr->size() - 1);
	return this->_IDarray.size() - 1;
}

void EntityManager::update()
{
	for (std::vector<Entity*>::iterator iterator = this->_entityArr->begin(); iterator != this->_entityArr->end(); iterator++) {
		Entity* entity = *iterator;
		//tile->update(player->getAtGridTile(), player->getEyeVector());
		entity->update();
	}
}

void EntityManager::removeEntity(int ID)
{
	//this->show();
	this->_entityArr->erase(_entityArr->begin() + _IDarray.at(ID));
	for (int i = ID; i < this->_IDarray.size(); i++) {
		if (_IDarray.at(i) > 0)_IDarray.at(i)--;
	}
	//this->show();
}

void EntityManager::show()
{

	cout << "show" << endl << this->_IDarray.size() << endl;;
	for (int i = 0; i < this->_IDarray.size(); i++) {
		cout << i << " " << this->_IDarray[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < this->_entityArr->size(); i++) {
		cout << this->_entityArr->at(i) << " ";
	}
	cout << endl << endl;
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


