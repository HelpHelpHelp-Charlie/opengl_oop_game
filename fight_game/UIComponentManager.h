#pragma once
#ifndef  __FightGame__UIComponentManager__
#define __FightGame__UIComponentManager__
#include"Timer.h"
#include<vector>
#include"Timer.h"
class UIComponentManager {
private:
	std::vector<AbstractUIComponent*>* _UIComponentArr;
	Timer *_timer;
	//std::vector<int>_IDarray;
public:
	UIComponentManager();
	std::vector<AbstractUIComponent *>* getUIComponentArr();
	void drawUI(double deltaTime);
	void update();
	//std::vector<int> getIDarray();
	//int addNewEntity(IngredientType type);
	//void update();
	//void removeEntity(int ID);
	//void show();
	static UIComponentManager& getUIComponentManager();
	static void destroyUIComponentManager();
};


#endif