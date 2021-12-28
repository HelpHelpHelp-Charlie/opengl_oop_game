#include "Scene.h"
//#include "CameraSystem.h"
#include "ResourceManager.h"
#include "Vec2.h"

//#include "PlayerInputSystem.h"
std::vector<Entity*>* Scene::getChildrenEntity()
{
	return _childrenEntity;
}


std::vector<Sprite *>* Scene::getChildrenSprite()
{
	return _childrenSprite;
}

std::vector<Player*>* Scene::getChildrenPlayer()
{
	return this->_childrenPlayer;
}

UIComponentManager * Scene::getUIComponentManager()
{
	return this->_uiComponentManager;
}


GridMap * Scene::getGridMap()
{
	return this->_gridmap;
}

void Scene::update()
{
	this->_childrenEntity = this->_entityManager->getEntityArr();
	_entityManager->update();
}

Scene::Scene()
{
	this->_entityManager = &EntityManager::getEntityManager();
	std::cout << "Scene is created" << std::endl;
	_childrenSprite = new std::vector<Sprite *>();
	_childrenPlayer = new std::vector<Player *>();
	_childrenEntity = new std::vector<Entity *>();
	_childrenUIComponent = new std::vector<AbstractUIComponent *>();
	ResourceManager *resourceManager = &ResourceManager::getResourceManager();
	this->_uiComponentManager= &UIComponentManager::getUIComponentManager();
	
	///////////map initialize
	this->_gridmap = new GridMap("scene_1_map.txt");
	///////player list initialize
	Sprite *mainPlayerSprite = new Sprite(resourceManager->getAnimatorArray()->at(0),
		Vec2(50, 50));

	Player *mainPlayer = new Player(mainPlayerSprite, _gridmap);
	this->_childrenPlayer->push_back(mainPlayer);

	////////// sprite initialize for render

   ///////////
	_childrenSprite->push_back(mainPlayerSprite);
}

Scene::~Scene()
{
	for (std::vector<Sprite *>::iterator iterator = _childrenSprite->begin(); iterator != _childrenSprite->end(); iterator++) {
		delete *iterator;
	}
	delete _childrenSprite;
	//for (std::vector<Player *>::iterator iterator = this->_childrenPlayer->begin(); iterator != this->_childrenPlayer->end(); iterator++) {
	//	delete *iterator;
	//}
	//delete this->_childrenPlayer;
//	delete this->_gridmap;
}