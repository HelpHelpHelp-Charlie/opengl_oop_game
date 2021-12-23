#ifndef  __FightGame__Scene__
#define __FightGame__Scene__

#include <iostream>
#include <vector>
#include "Sprite.h"
#include"GridMap.h"
#include"Player.h"
#include"HighLightSign.h"
#include"EntityManager.h"
class Scene
{
private:
    
    std::vector<Sprite *> *_childrenSprite;
	std::vector<Player *> *_childrenPlayer;
	std::vector<Entity *> *_childrenEntity;
	GridMap*_gridmap;
	EntityManager* _entityManager;
public:
	std::vector<Entity *>* getChildrenEntity();
    std::vector<Sprite *>* getChildrenSprite();
	std::vector<Player *>* getChildrenPlayer();
	GridMap* getGridMap();
	void update();
    Scene();
    ~Scene();
   
};

#endif

