#pragma once
#ifndef  __FightGame__TileBuilder__
#define __FightGame__TileBuilder__
#include"Tile.h"
#include"Table.h"
#include"Texture.h"
#include"Animation2D.h"
#include"Animator.h"
#include"VertexBuffer.h"
#include"Sprite.h"
#include"Vec2.h"


enum TileBuilderType {
	TABLEBuilder, STOVEBuilder, MEATBOXBuilder, NumberOfBuilderItem
};

class TileBuilder 
{

protected:
	Texture *_texture;
	std::vector<VertexBuffer *> *_vertexBufferArray;
	std::vector<Animator *>*_animatorArray;
public:	
	//virtual Sprite* getResult(Vec2 pos) = 0;
	virtual Tile* getResult(Vec2 pos) = 0;
	/*virtual void BuildTexture();*/
};

#endif