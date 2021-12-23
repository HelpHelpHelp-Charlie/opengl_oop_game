//
//  Sprite.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 11/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "Sprite.h"


Vec2 Sprite::getPosition()
{
	return _position;
}

void Sprite::setPosition(Vec2 newPosition)
{
	this->_position = newPosition;
}


Animator *Sprite::getAnimator()
{
    return _animator;
}

void Sprite::setAnimator(Animator *newAnimator)
{
	_animator = newAnimator;
}

int Sprite::getNowAnimate_No()
{
	return this->_nowAnimate_No;
}


void Sprite::setNowAnimate_No(int newNum)
{
	this->_nowAnimate_No = newNum;
}

Sprite::Sprite()
{
	this->_animator = new Animator();
	this->_position =Vec2(0, 0);
	this->_nowAnimate_No = 0;
}

Sprite::Sprite(Animator *newAnimator, Vec2 position):
_animator(newAnimator), _position(position)
{
	this->_nowAnimate_No = 0;
}

Sprite::~Sprite()
{
    
}