#pragma once
#ifndef  __FightGame__UIComponentManager__
#define __FightGame__UIComponentManager__
#include"Timer.h"
#include<vector>
#include"Timer.h"
#include"ScoreBoard.h"
class UIComponentManager {
private:
	std::vector<AbstractUIComponent*>* _UIComponentArr;
	Timer *_timer;
	ScoreBoard *_scoreBoard;
	//std::vector<int>_IDarray;
public:
	UIComponentManager();
	std::vector<AbstractUIComponent *>* getUIComponentArr();
	void drawUI(double deltaTime);
	void update();
	ScoreBoard* getscoreBoard() { return this->_scoreBoard; }
	//std::vector<int> getIDarray();
	//int addNewEntity(IngredientType type);
	//void update();
	//void removeEntity(int ID);
	//void show();
	static UIComponentManager& getUIComponentManager();
	static void destroyUIComponentManager();
};


#endif