#pragma once
#ifndef  __FightGame__Stove__
#define __FightGame__Stove__
#include"Tile.h"
#include"ProgressBar.h"
#include"InPutThing.h"
#include"grabFromBoxh.h"
class Stove :
	public Tile
{
public :
	Stove(Sprite* e) { _sprite = e; this->_HighLightSign = new HighLightSign(this->getSprite()->getPosition()); 
	this->_progressBar = new ProgressBar(this->getSprite()->getPosition(), 5); this->_entityManager = &EntityManager::getEntityManager();
	this->_inputThing = new InPutThing(this->stoveInput); this->_grabFromBox = new GrabFromBox();
	this->_grabFromBox->setEnable(false); this->_inputThing->setEnable(true); this->_progressBar->notShow();
	}
	~Stove();
	 Sprite* getSprite() { return this->_sprite;}
	 void setSprite(Sprite &sprite) { this->_sprite = &sprite; }
	 Sprite* getProgressBarSprite() { return this->_progressBar->getSprite(); };

	 void update(Player* player) {
		// this->_progressBar->setVisibility(this->_progressBar->trigger(this->getSprite()->getPosition(), player));
		 this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getSprite()->getPosition(), player));

		 //////
		 if (this->_inputThing->Input(this->_inputThing->trigger(this->getSprite()->getPosition(), player), player, this)) {
			 this->_inputThing->setEnable(false);
			 this->_progressBar->setEnable(true);
			 this->_sprite->setNowAnimate_No(1);
		 }
		 if (this->_progressBar->onuse()) {
			 this->_grabFromBox->setEnable(true);
			 this->_progressBar->show();
			 this->_sprite->setNowAnimate_No(0);
		} 
		if( this->_grabFromBox->grab(this->_grabFromBox->trigger(this->getSprite()->getPosition(), player), player, stoveOutput)) {
			this->_progressBar->notShow();
			this->_grabFromBox->setEnable(false);
			this->_inputThing->setEnable(true);
			this->_progressBar->setEnable(false);

		 }
	 }


private:
	GrabFromBox *_grabFromBox;
	ProgressBar *_progressBar;
	InPutThing *_inputThing;
	IngredientType stoveInput = IngredientType::RAWPATTIES;
	IngredientType stoveOutput = IngredientType::COOKEDPATTIES;

};

#endif