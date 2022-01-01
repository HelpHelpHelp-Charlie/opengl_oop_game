#pragma once
#ifndef  __FightGame__ConcreteIngredient__
#define __FightGame__ConcreteIngredient__
#include"Ingredient.h"
class Meat :
	public Ingredient {

private:
protected:

public:
	Meat() {
		this->imgName = "Ingredient.tga";
		this->AnimationFrameData = Vec4(0, 256, 128, 128);
		this->makeSprite(Vec2(400, 400), Vec4(128, 128, 9, 1));
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
		this->AnimationFrameData = Vec4(0, 5 * 128, 128, 128);
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

class Buger :
	public Ingredient {

private:
protected:

public:
	Buger() {
		this->imgName = "Ingredient.tga";
		this->AnimationFrameData = Vec4(0, 6 * 128, 128, 128);
		this->makeSprite(Vec2(400, 400), Vec4(128, 128, 9, 1));
		this->type = IngredientType::BUGER;
		this->setSpriteOffset(Vec2(15, 15));
	}
};


class Plate :
	public Ingredient {

private:
protected:

public:
	Plate() {
		this->imgName = "Ingredient.tga";
		this->AnimationFrameData = Vec4(0, 1 * 128, 128, 128);
		this->makeSprite(Vec2(400, 400), Vec4(128, 128, 9, 1));
		this->type = IngredientType::PLATE;
		this->setSpriteOffset(Vec2(15, 15));
	}
};

class Plate_Buger :
	public Ingredient {

private:
protected:

public:
	Plate_Buger() {
		this->imgName = "Ingredient.tga";
		this->AnimationFrameData = Vec4(0, 9 * 128, 128, 128);
		this->makeSprite(Vec2(400, 400), Vec4(128, 128, 9, 1));
		this->type = IngredientType::PLATE_BUGER;
		this->setSpriteOffset(Vec2(15, 15));
	}
};

class Plate_Patties :
	public Ingredient {

private:
protected:

public:
	Plate_Patties() {
		this->imgName = "Ingredient.tga";
		this->AnimationFrameData = Vec4(0, 7 * 128, 128, 128);
		this->makeSprite(Vec2(400, 400), Vec4(128, 128, 9, 1));
		this->type = IngredientType::PLATE_PATTIES;
		this->setSpriteOffset(Vec2(15, 15));
	}
};
class Plate_Bun :
	public Ingredient {

private:
protected:

public:
	Plate_Bun() {
		this->imgName = "Ingredient.tga";
		this->AnimationFrameData = Vec4(0, 8 * 128, 128, 128);
		this->makeSprite(Vec2(400, 400), Vec4(128, 128, 9, 1));
		this->type = IngredientType::PLATE_BUN;
		this->setSpriteOffset(Vec2(15, 15));
	}


};



#endif