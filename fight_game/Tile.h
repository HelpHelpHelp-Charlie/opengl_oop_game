#pragma once
#ifndef  __FightGame__Tile__
#define __FightGame__Tile__
#include"collision2D.h"
#include"Sprite.h"
#include"HighLightSign.h"
#include"EntityManager.h"


enum TileType {
	TABLE,STOVE,MEATBOX,TRASHCAN,BUNBOX,FORMER,PLATEBOX,PICKUPBAR,NumberOfAnimalItem
};


class Tile {
public:

	virtual Sprite* getSprite() = 0;
	virtual Sprite* getHighLightSignSprite() {return this->_HighLightSign->getSprite();};
	virtual Sprite* getProgressBarSprite() { return nullptr; }
	virtual void setSprite(Sprite &sprite) = 0;
	virtual void update(Player* player) {
		//this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getSprite()->getPosition(), player->getAtGridTile(), player->getEyeVector()));
		this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getSprite()->getPosition(),player));
	}


	int getGrabEntityID() { return this->_grabEntityID; }
	void setGrabEntityID(int ID) { this->_grabEntityID = ID; }

	bool getIsGrabingThing() { return this->_isGrabingThing; }
	void setIsGrabingThing(bool i) { this->_isGrabingThing = i; }

protected:
	bool _isGrabingThing = false;
	int _grabEntityID = 9;
	EntityManager*_entityManager;

	HighLightSign *_HighLightSign;
	Sprite *_sprite;

};

#endif