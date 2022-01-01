#pragma once
#ifndef  __FightGame__PickUpBar__
#define __FightGame__PickUpBar__
#include"InPutThing.h"
#include"UIComponentManager.h"
class PickUpBar :
	public Tile
{
public:
	PickUpBar(Sprite* e) {
		_sprite = e;  this->_HighLightSign = new HighLightSign(this->getSprite()->getPosition());
		this->_inPutThing = new InPutThing(IngredientType::PLATE_BUGER); this->_entityManager = &EntityManager::getEntityManager();
		this->_UIManager = &UIComponentManager::getUIComponentManager();this->_inPutThing->setEnable(true);
		
	}
	~PickUpBar();
	Sprite* getSprite() { return this->_sprite; }
	void setSprite(Sprite &sprite) { this->_sprite = &sprite; }
	void update(Player* player) {
		if (this->_sprite->getAnimator()->_animation2DArray->at(1)->getCurrentFrameIndex() == 0) {

			this->_sprite->setNowAnimate_No(0); this->_sprite->getAnimator()->_animation2DArray->at(1)->setCurrentFrameIndex(0);
		}

		this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getSprite()->getPosition(), player));
		if (this->_inPutThing->Input(this->_inPutThing->trigger(this->getSprite()->getPosition(), player), player, this)) {
			_UIManager->getscoreBoard()->setScore(_UIManager->getscoreBoard()->getScore() + 50);
			this->_sprite->setNowAnimate_No(1);
		}

	}

private:
	InPutThing* _inPutThing;
	UIComponentManager *_UIManager;
};

#endif



