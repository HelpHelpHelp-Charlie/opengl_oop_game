#pragma once
#ifndef  __FightGame__Stove__
#define __FightGame__Stove__
#include"Tile.h"
class Stove :
	public Tile
{
public :
	Stove(Sprite* e) { _sprite = e; this->_HighLightSign = new HighLightSign(this->getSprite()->getPosition()); }
	~Stove();
	 Sprite* getSprite() { return this->_sprite;}
	 void setSprite(Sprite &sprite) { this->_sprite = &sprite; }
};

#endif