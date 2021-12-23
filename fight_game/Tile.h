#pragma once
#ifndef  __FightGame__Tile__
#define __FightGame__Tile__
#include"collision2D.h"
#include"Sprite.h"
#include"HighLightSign.h"

enum TileType {
	TABLE,STOVE,MEATBOX,NumberOfAnimalItem
};


class Tile {
public:

	virtual Sprite* getSprite() = 0;
	Sprite* getHighLightSignSprite() {return this->_HighLightSign->getSprite();};
	virtual void setSprite(Sprite &sprite) = 0;
	void update(Player* player) {
		//this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getSprite()->getPosition(), player->getAtGridTile(), player->getEyeVector()));
		this->_HighLightSign->setVisibility(this->_HighLightSign->trigger(this->getSprite()->getPosition(),player));
	}

protected:

	HighLightSign *_HighLightSign;
	Sprite *_sprite;

};

#endif