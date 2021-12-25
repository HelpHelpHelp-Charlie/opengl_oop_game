#pragma once
#ifndef  __FightGame__Trashcan__
#define __FightGame__Trashcan__
#include"Tile.h"
#include"InPutThing.h"
class Trashcan :
	public Tile
{
public:
	Trashcan(Sprite* e) {
		_sprite = e;  this->_HighLightSign = new HighLightSign(this->getSprite()->getPosition());
		 //this->_entityManager = &EntityManager::getEntityManager();
		 this->inputThing = new InPutThing();
		 this->inputThing->setEnable(true);
	}
	~Trashcan();
	Sprite* getSprite() { return this->_sprite; }
	void setSprite(Sprite &sprite) { this->_sprite = &sprite; }
	void update(Player* player) {		
		if (this->_sprite->getAnimator()->_animation2DArray->at(1)->getCurrentFrameIndex() == 7) {

				this->_sprite->setNowAnimate_No(0); this->_sprite->getAnimator()->_animation2DArray->at(1)->setCurrentFrameIndex(0);
			}
		this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getSprite()->getPosition(), player));
		if (this->inputThing->Input(this->inputThing->trigger(this->getSprite()->getPosition(), player), player, this)) {
				this->_sprite->setNowAnimate_No(1);
		}
		
	}

private:
	InPutThing* inputThing;
};

#endif

