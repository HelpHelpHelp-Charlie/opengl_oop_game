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
		this->type = IngredientType::MEAT;
		this->setSpriteOffset(Vec2(15, 15));
	}
};


class Bun :
	public Ingredient {

private:
protected:

public:
	Bun() {
		this->imgName = "Ingredient.tga";
		this->AnimationFrameData = Vec4(0, 5*128, 128, 128);
		this->makeSprite(Vec2(400, 400), Vec4(128, 128, 9, 1));
		this->type = IngredientType::BUN;
		this->setSpriteOffset(Vec2(15, 15));
	}
};


class CookedPatties :
	public Ingredient {

private:
protected:

public:
	CookedPatties() {
		this->imgName = "Ingredient.tga";
		this->AnimationFrameData = Vec4(0, 4 * 128, 128, 128);
		this->makeSprite(Vec2(400, 400), Vec4(128, 128, 9, 1));
		this->type = IngredientType::COOKEDPATTIES;
		this->setSpriteOffset(Vec2(15, 15));
	}
};

class RawPatties :
	public Ingredient {

private:
protected:

public:
	RawPatties() {
		this->imgName = "Ingredient.tga";
		this->AnimationFrameData = Vec4(0, 3 * 128, 128, 128);
		this->makeSprite(Vec2(400, 400), Vec4(128, 128, 9, 1));
		this->type = IngredientType::RAWPATTIES;
		this->setSpriteOffset(Vec2(15, 15));
	}
};


#endif