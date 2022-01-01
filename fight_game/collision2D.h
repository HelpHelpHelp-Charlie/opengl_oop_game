#pragma once
#include"Rect.h"

#ifndef  __FightGame__Collision2D__
#define __FightGame__Collision2D__
class Collision2D {
public:
	Collision2D() :_rect(10,10,10,10) {};
	Collision2D(Rect rect) :_rect(rect) {};
	~Collision2D() {};
	Rect getRect() { return this->_rect; };
	void setRect(Rect rect) { this->_rect = rect; }

private:
	Rect _rect;

};

#endif