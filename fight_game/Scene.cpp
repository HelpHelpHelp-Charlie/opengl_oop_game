#include "Scene.h"
//#include "CameraSystem.h"
#include "ResourceManager.h"
#include "Vec2.h"
//#include "PlayerInputSystem.h"

std::vector<Entity *>* Scene::getChildren()
{
    return _children;
}

Scene::Scene()
{
	std::cout << "Scene is created" << std::endl;
    _children = new std::vector<Entity *>();
    
    ResourceManager *resourceManager = &ResourceManager::getResourceManager();
    Entity *entity =new Entity(resourceManager->getAnimatorArray()->at(0),
                       Vec2(50, 50));

    _children->push_back(entity);

}

Scene::~Scene()
{
    for (std::vector<Entity *>::iterator iterator = _children->begin(); iterator != _children->end(); iterator++) {
        delete *iterator;
    }
    
    delete _children;
}