#pragma once
#ifndef  __FightGame__Table__
#define __FightGame__Table__
#include"Tile.h"
class Table:
	public Tile
{
public:
	Table(Sprite* e) { _sprite = e;  this->_HighLightSign = new HighLightSign(this->getSprite()->getPosition()); }
	~Table();
	 Sprite* getSprite() { return this->_sprite;}
	 void setSprite(Sprite &sprite) { this->_sprite = &sprite; }
};

#endif
