#pragma once

#ifndef  __FightGame__AbstractFormula__
#define __FightGame__AbstractFormula__

#include"Ingredient.h"
#include<string>
class AbstractFormula {
private:
protected:
	string _formulaName;
	IngredientType _ingredientA;
	IngredientType _ingredientB;
	IngredientType _result;
public:
	IngredientType getResult(IngredientType A, IngredientType B) {
		if ((A == _ingredientA&&B == _ingredientB)|| (B == _ingredientA&&A == _ingredientB)) {
			cout << "_ingredientA" << _ingredientA << "  _ingredientB" << _ingredientB << " result "<< _result << endl;
			return this->_result;
		}
		else {
			return IngredientType::NumberOfIngredientItem;
		}
	}
	std::string getName() { return this->_formulaName; }
};

#endif