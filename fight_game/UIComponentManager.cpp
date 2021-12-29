#include "UIComponentManager.h"

UIComponentManager::UIComponentManager()
{
	this->_timer = new Timer();
	this->_scoreBoard = new ScoreBoard();
	this->_UIComponentArr = new std::vector<AbstractUIComponent*>;
	this->_UIComponentArr->push_back(_timer);
	this->_UIComponentArr->push_back(_scoreBoard);
}

std::vector<AbstractUIComponent*>* UIComponentManager::getUIComponentArr()
{
	return this->_UIComponentArr;
}

void UIComponentManager::drawUI(double deltaTime)
{
	for (std::vector<AbstractUIComponent *>::iterator iterator = this->_UIComponentArr->begin(); iterator != this->_UIComponentArr->end(); iterator++) {
		AbstractUIComponent *UI = *iterator;
		UI->draw(deltaTime);
	}
}

void UIComponentManager::update()
{
	for (std::vector<AbstractUIComponent *>::iterator iterator = this->_UIComponentArr->begin(); iterator != this->_UIComponentArr->end(); iterator++) {
		AbstractUIComponent *UI = *iterator;
		UI->update();
	}
}


UIComponentManager & UIComponentManager::getUIComponentManager()
{
	static UIComponentManager *_UIComponentManager = NULL;

	if (_UIComponentManager == NULL) {
		_UIComponentManager = new UIComponentManager();

	}

	return *_UIComponentManager;
}


void UIComponentManager::destroyUIComponentManager()
{

	UIComponentManager *_UIComponentManager = &getUIComponentManager();
	delete _UIComponentManager;
}
