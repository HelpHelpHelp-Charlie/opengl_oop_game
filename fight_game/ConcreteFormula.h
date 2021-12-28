#pragma once
#ifndef  __FightGame__ConcreteFormula__
#define __FightGame__ConcreteFormula__
#include"AbstractFormula.h"
class BugerFormula :
	public AbstractFormula {
public:
	BugerFormula() {
		this->_formulaName = "BugerFormula";
		this->_ingredientA = IngredientType::BUN;
		this->_ingredientB = IngredientType::COOKEDPATTIES;
		this->_result = IngredientType::BUGER;
	}
};

class Plate_BunFormula :
	public AbstractFormula {
public:
	Plate_BunFormula() {
		this->_formulaName = "Plate_BunFormula";
		this->_ingredientA = IngredientType::PLATE;
		this->_ingredientB = IngredientType::BUN;
		this->_result = IngredientType::PLATE_BUN;
	}
};

class Plate_MeatFormula :
	public AbstractFormula {
public:
	Plate_MeatFormula() {
		this->_formulaName = "Plate_MeatFormula";
		this->_ingredientA = IngredientType::PLATE;
		this->_ingredientB = IngredientType::COOKEDPATTIES;
		this->_result = IngredientType::PLATE_PATTIES;
	}
};








class Plate_BugerFormula :
	public AbstractFormula {
public:
	Plate_BugerFormula() {
		this->_formulaName = "Plate_BugerFormula";
		this->_ingredientA = IngredientType::PLATE;
		this->_ingredientB = IngredientType::BUGER;
		this->_result = IngredientType::PLATE_BUGER;
	}
};

class Plate_BugerFormula2 :
	public AbstractFormula {
public:
	Plate_BugerFormula2() {
		this->_formulaName = "Plate_BugerFormula2";
		this->_ingredientA = IngredientType::PLATE_BUN;
		this->_ingredientB = IngredientType::COOKEDPATTIES;
		this->_result = IngredientType::PLATE_BUGER;
	}
};

class Plate_BugerFormula3 :
	public AbstractFormula {
public:
	Plate_BugerFormula3() {
		this->_formulaName = "Plate_BugerFormula3";
		this->_ingredientA = IngredientType::PLATE_PATTIES;
		this->_ingredientB = IngredientType::BUN;
		this->_result = IngredientType::PLATE_BUGER;
	}
};

#endif