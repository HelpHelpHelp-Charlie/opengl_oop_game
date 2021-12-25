#pragma once
#ifndef  __FightGame__BunBox__
#define __FightGame__BunBox__
#include"Tile.h"
#include"grabFromBoxh.h"
class BunBox :
	public Tile
{
public:
	BunBox(Sprite* e) {
		_sprite = e; this->_HighLightSign = new HighLightSign(this->getSprite()->getPosition());
		this->_grabFromBox = new GrabFromBox(); this->_entityManager = &EntityManager::getEntityManager();
	}
	//
	~BunBox();
	Sprite* getSprite() { return this->_sprite; }
	void setSprite(Sprite &sprite) { this->_sprite = &sprite; }

	void update(Player* player) {
		if (this->_sprite->getAnimator()->_animation2DArray->at(1)->getCurrentFrameIndex() == 8) {
			this->_sprite->setNowAnimate_No(0); this->_sprite->getAnimator()->_animation2DArray->at(1)->setCurrentFrameIndex(0);
		}

		this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getSprite()->getPosition(), player));
		if (this->_grabFromBox->grab(this->_grabFromBox->trigger(this->getSprite()->getPosition(), player), player, IngredientType::BUN)) {
			this->_sprite->setNowAnimate_No(1);
		}
		// this->_grabFromBox
	}

private:
	GrabFromBox *_grabFromBox;
};

#endif

