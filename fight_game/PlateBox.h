#pragma once
#ifndef  __FightGame__PlateBox__
#define __FightGame__PlateBox__
#include"Tile.h"
#include"grabFromBoxh.h"
class PlateBox :
	public Tile
{
public:
	PlateBox(Sprite* e) {
		_sprite = e; this->_HighLightSign = new HighLightSign(this->getSprite()->getPosition());
		this->_grabFromBox = new GrabFromBox(); this->_entityManager = &EntityManager::getEntityManager();
	}
	//
	~PlateBox();
	Sprite* getSprite() { return this->_sprite; }
	void setSprite(Sprite &sprite) { this->_sprite = &sprite; }

	void update(Player* player) {
		if (this->_sprite->getAnimator()->_animation2DArray->at(1)->getCurrentFrameIndex() == 8) {
			this->_sprite->setNowAnimate_No(0); this->_sprite->getAnimator()->_animation2DArray->at(1)->setCurrentFrameIndex(0);
		}

		this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getSprite()->getPosition(), player));
		if (this->_grabFromBox->grab(this->_grabFromBox->trigger(this->getSprite()->getPosition(), player), player, IngredientType::PLATE)) {
			this->_sprite->setNowAnimate_No(1);
		}
		// this->_grabFromBox
	}

private:
	GrabFromBox *_grabFromBox;
};

#endif

