#ifndef  __FightGame__Scene__
#define __FightGame__Scene__

#include <iostream>
#include <vector>
#include "Entity.h"

class Scene
{
private:
    
    std::vector<Entity *> *_children;
    
public:
    
    std::vector<Entity *>* getChildren();
    
    Scene();
    ~Scene();
   
};

#endif

