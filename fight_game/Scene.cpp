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

GridMap * Scene::getGridMap()
{
	return this->_gridmap;
}

void Scene::update()
{
	this->_childrenEntity = this->_entityManager->getEntityArr();
}

Scene::Scene()
{
	this->_entityManager = new EntityManager;
	std::cout << "Scene is created" << std::endl;
	_childrenSprite = new std::vector<Sprite *>();
	_childrenPlayer = new std::vector<Player *>();
	_childrenEntity = new std::vector<Entity *>();
	ResourceManager *resourceManager = &ResourceManager::getResourceManager();

	
	///////////map initialize
	this->_gridmap = new GridMap("scene_1_map.txt");
	///////player list initialize
	Sprite *mainPlayerSprite = new Sprite(resourceManager->getAnimatorArray()->at(0),
		Vec2(50, 50));

	Player *mainPlayer = new Player(mainPlayerSprite, _gridmap);
	this->_childrenPlayer->push_back(mainPlayer);

	////////// sprite initialize for render


   ///////////
	//_childrenSprite->insert(_childrenSprite->end(), this->_gridmap->_spriteArray->begin(), this->_gridmap->_spriteArray->end());
	_childrenSprite->push_back(mainPlayerSprite);
	//_childrenSprite->insert(_childrenSprite->end(), this->_gridmap->_spriteHighLightSignArray->begin(), this->_gridmap->_spriteHighLightSignArray->end());
	



	_entityManager->addNewEntity(IngredientType::MEAT,Vec2(400,400));
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