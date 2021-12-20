#include "Scene.h"
//#include "CameraSystem.h"
#include "ResourceManager.h"
#include "Vec2.h"
#include"player.h"
//#include "PlayerInputSystem.h"

std::vector<Entity *>* Scene::getChildrenEntity()
{
    return _childrenEntity;
}

std::vector<Player*>* Scene::getChildrenPlayer()
{
	return this->_childrenPlayer;
}

GridMap * Scene::getGridMap()
{
	return this->_gridmap;
}

Scene::Scene()
{
	std::cout << "Scene is created" << std::endl;
    _childrenEntity = new std::vector<Entity *>();
	_childrenPlayer = new std::vector<Player *>();

    ResourceManager *resourceManager = &ResourceManager::getResourceManager();


	///////////map initialize
	 this->_gridmap = new GridMap("scene_1_map.txt");
	///////player list initialize
    Entity *mainPlayerEntity =new Entity(resourceManager->getAnimatorArray()->at(0),
                       Vec2(50, 50));
	
	Player *mainPlayer = new Player(mainPlayerEntity, _gridmap);
	this->_childrenPlayer->push_back(mainPlayer);

	 ////////// entity initialize for render
	
	 _childrenEntity->insert(_childrenEntity->end(), this->_gridmap->_entityArray->begin(), this->_gridmap->_entityArray->end());
	_childrenEntity->push_back(mainPlayerEntity);

}

Scene::~Scene()
{
    for (std::vector<Entity *>::iterator iterator = _childrenEntity->begin(); iterator != _childrenEntity->end(); iterator++) {
        delete *iterator;
    }
    delete _childrenEntity;
	//for (std::vector<Player *>::iterator iterator = this->_childrenPlayer->begin(); iterator != this->_childrenPlayer->end(); iterator++) {
	//	delete *iterator;
	//}
	//delete this->_childrenPlayer;
//	delete this->_gridmap;
}