#pragma once
#ifndef  __FightGame__ConcreteIngredient__
#define __FightGame__ConcreteIngredient__
#include"Ingredient.h"
class Meat:
public Ingredient{

private:
protected:
	
public:
	Meat() {
		this->imgName = "Ingredient.tga"; 
		this->AnimationFrameData=Vec4(0, 256, 128, 128);
		this->makeSprite(Vec2(400,400),Vec4(128, 128, 9, 1));
	}
public:
};

#endif