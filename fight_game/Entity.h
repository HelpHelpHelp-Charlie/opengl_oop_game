#pragma once

#ifndef  __FightGame__Entity__
#define __FightGame__Entity__
#include<string>
#include"Texture.h"
#include"Animation2D.h"
#include"Animator.h"
#include"Sprite.h"

class Entity {
public:
	void makeSprite(Vec2 pos, Vec4 textureSetting);
	void setID(int newID) ;
	int getID() ;
	Vec2 getPos() { return this->_pos; }
	void setPos(Vec2 pos) { this->_pos = pos; }
	Sprite* getSprite();
	void update();
protected:
	Vec2 _pos;
	int _id_InTheScene;
	Sprite *_sprite;
	std::string imgName = "Ingredient.tga";
	Vec4 AnimationFrameData;
private:

};


#endif