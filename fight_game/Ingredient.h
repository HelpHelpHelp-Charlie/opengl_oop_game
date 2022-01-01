#pragma once
#ifndef  __FightGame__Ingredient__
#define __FightGame__Ingredient__
#include "Entity.h"
enum IngredientType {
	PLATE, MEAT, RAWPATTIES, COOKEDPATTIES, BUN, BUGER, PLATE_PATTIES, PLATE_BUN, PLATE_BUGER, NumberOfIngredientItem
};
//const char* ToString(IngredientType value)
//{
//	static char *table[] = { "PLATE", "MEAT", "RAWPATTIES","COOKEDPATTIES","BUN" ,"BUGGER","PLATE_MEAT","PLATE_BUN","PLATE_BUGGER"};
//	return table[value];
//}

class Ingredient:
public Entity
{
private:
protected:
	IngredientType type;
public:
	int getType() { return int(this->type); };
};
#endif