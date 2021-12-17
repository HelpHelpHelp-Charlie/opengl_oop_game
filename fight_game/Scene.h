#ifndef  __FightGame__Scene__
#define __FightGame__Scene__

#include <iostream>
#include <vector>
#include "Entity.h"
#include"GridMap.h"

class Scene
{
private:
    
    std::vector<Entity *> *_children;
	GridMap*_gridmap;

public:
    
    std::vector<Entity *>* getChildren();
	GridMap* getGridMap();
    Scene();
    ~Scene();
   
};

#endif

