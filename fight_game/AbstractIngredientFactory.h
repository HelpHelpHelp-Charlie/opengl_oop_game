#pragma once
//#include"ConcreteAnimal.h"
#include"Vec2.h"
class AbstractIngredientFactory {
private:
	Vec2 _pos;
public:
	virtual void update()=0;
};

