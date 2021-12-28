#include "Vec2.h"
#include"ConcreteFormula.h"
#ifndef __SimpleFPS__MachingSystem__
#define __SimpleFPS__MachingSystem__
class MachingSystem
{
private:

	MachingSystem() {
		BugerFormula *Fb = new BugerFormula();
		Plate_BugerFormula*Fpbuger = new Plate_BugerFormula();
		Plate_BunFormula* Fpbun = new Plate_BunFormula();
		Plate_MeatFormula* Fpm = new Plate_MeatFormula();
		Plate_BugerFormula2*Fpbuger2 = new Plate_BugerFormula2();
		Plate_BugerFormula3*Fpbuger3 = new Plate_BugerFormula3();
		////
		this->_formulaArray = new std::vector<AbstractFormula *>();
		this->_formulaArray->push_back(Fb);
		this->_formulaArray->push_back(Fpbuger);
		this->_formulaArray->push_back(Fpbun);
		this->_formulaArray->push_back(Fpm);
		this->_formulaArray->push_back(Fpbuger2);
		this->_formulaArray->push_back(Fpbuger3);
	}
	~MachingSystem() {};

	std::vector<AbstractFormula *> *_formulaArray;
public:

	std::vector<AbstractFormula *> getFormula() { this->_formulaArray; }
	static MachingSystem& getMachingSystem() {
		static MachingSystem* machingSystem = NULL;
		if (machingSystem == NULL) {
			machingSystem = new MachingSystem();
		}
		return *machingSystem;
	};

	IngredientType matching(IngredientType A, IngredientType B) {
		for (std::vector<AbstractFormula *>::iterator iterator = this->_formulaArray->begin(); iterator != this->_formulaArray->end(); iterator++) {
			
			AbstractFormula *formula = *iterator;
			//return IngredientType::RAWPATTIES;
			if (formula->getResult(A, B)!= IngredientType::NumberOfIngredientItem)return formula->getResult(A, B);
		}
		return IngredientType::NumberOfIngredientItem;
	}

	static void destroyMachingSystem() {
		MachingSystem *machingSystem = &getMachingSystem();
		delete machingSystem;
	};
};


#endif
