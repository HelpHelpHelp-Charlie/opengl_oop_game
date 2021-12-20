//
//  Entity.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 11/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "Entity.h"


Vec2 Entity::getPosition()
{
	return _position;
}

void Entity::setPosition(Vec2 newPosition)
{
	this->_position = newPosition;
}


Animator *Entity::getAnimator()
{
    return _animator;
}

void Entity::setAnimator(Animator *newAnimator)
{
	_animator = newAnimator;
}

int Entity::getNowAnimate_No()
{
	return this->_nowAnimate_No;
}


void Entity::setNowAnimate_No(int newNum)
{
	this->_nowAnimate_No = newNum;
}

Entity::Entity()
{
	this->_animator = new Animator();
	this->_position =Vec2(0, 0);
	this->_nowAnimate_No = 0;
}

Entity::Entity(Animator *newAnimator, Vec2 position):
_animator(newAnimator), _position(position)
{
	this->_nowAnimate_No = 0;
}

Entity::~Entity()
{
    
}