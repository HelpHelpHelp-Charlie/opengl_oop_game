#ifndef  __FightGame__Scene__
#define __FightGame__Scene__

#include <iostream>
#include <vector>
#include "Entity.h"
#include"GridMap.h"
#include"Player.h"
class Scene
{
private:
    
    std::vector<Entity *> *_childrenEntity;
	std::vector<Player *> *_childrenPlayer;
	GridMap*_gridmap;

public:
    
    std::vector<Entity *>* getChildrenEntity();
	std::vector<Player *>* getChildrenPlayer();
	GridMap* getGridMap();
    Scene();
    ~Scene();
   
};

#endif

