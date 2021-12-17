#ifndef  __FightGame__ResourceManager__
#define __FightGame__ResourceManager__


#include <iostream>
#include <vector>
#include "VertexBuffer.h"
#include "Texture.h"
#include"VertexData.h"
#include"Animation2D.h"
#include"Animator.h"
#include"GridMap.h"
class ResourceManager
{
private:
    std::vector<VertexBuffer *> *_vertexBufferArray;  
	std::vector<Texture *>*_textureArray;
	std::vector<Animator *>*_animatorArray;
	//GridMap* _gridMap;
	void objectAnimator(int object_no);
    ResourceManager();
    ~ResourceManager();
	
public:
	std::vector<Texture *>* getTextureArray();
    std::vector<VertexBuffer *>* getVertexBufferArray();   
	std::vector<Animator *>*getAnimatorArray();
	GridMap* getGridMap();
    static ResourceManager& getResourceManager();
    static void destroyResourceManager();
    
};


#endif