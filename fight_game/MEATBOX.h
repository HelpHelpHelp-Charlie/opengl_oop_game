#pragma once
#ifndef  __FightGame__MeatBox__
#define __FightGame__MeatBox__
#include"Tile.h"
class MeatBox :
	public Tile
{
public:
	MeatBox(Sprite* e) { _sprite = e; this->_HighLightSign = new HighLightSign(this->getSprite()->getPosition()); }
	//
	~MeatBox();
	 Sprite* getSprite() { return this->_sprite; }
	 void setSprite(Sprite &sprite) { this->_sprite = &sprite; }

};

#endif

