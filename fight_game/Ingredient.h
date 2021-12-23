#pragma once
#ifndef  __FightGame__Ingredient__
#define __FightGame__Ingredient__
#include "Entity.h"
enum IngredientType {
	PLATE, MEAT, RAWPATTIES, COOKEDPATTIES, BUN, BUGGER, PLATE_MEAT, PLATE_BUN, PLATE_BUGGER, NumberOfIngredientItem
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

public:

};
#endif