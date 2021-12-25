#pragma once
#ifndef  __FightGame__Table__
#define __FightGame__Table__
#include"Tile.h"
#include"PlaceThing.h"
#include"takeThing.h"
class Table:
	public Tile
{
public:
	Table(Sprite* e) { _sprite = e;  this->_HighLightSign = new HighLightSign(this->getSprite()->getPosition()); 
	this->_placeThing = new PlaceThing(); this->_entityManager = &EntityManager::getEntityManager();
	this->_takeThing = new TakeThing();
	}
	~Table();
	 Sprite* getSprite() { return this->_sprite;}
	 void setSprite(Sprite &sprite) { this->_sprite = &sprite; }
	 void update(Player* player) {
		 this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getSprite()->getPosition(), player));
		 this->_placeThing->Place(this->_placeThing->trigger(this->getSprite()->getPosition(), player), player, this, !this->_takeThing->getEnable());
		 if (this->_isGrabingThing)this->_entityManager->getEntityArr()->at(this->_entityManager->getIDarray().at(this->_grabEntityID))->setPos(this->_sprite->getPosition());

		 this->_takeThing->Take(this->_placeThing->trigger(this->getSprite()->getPosition(), player), player, this,!this->_placeThing->getEnable());
	 }

private:
	PlaceThing* _placeThing;
	TakeThing* _takeThing;
};

#endif
