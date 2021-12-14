//
//  Entity.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 11/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "Entity.h"

Animator *Entity::getAnimator()
{
    return _animator;
}

void Entity::setAnimator(Animator *newAnimator)
{
	_animator = newAnimator;
}

Vec2 Entity::getPosition()
{
    return _position;
}

void Entity::setPosition(Vec2 newPosition)
{
    _position = newPosition;
}

Vec2 Entity::getScale()
{
    return _scale;
}

void Entity::setScale(Vec2 newScale)
{
    _scale = newScale;
}

GLfloat Entity::getRotation()
{
    return _rotation;
}

void Entity::setRotation(GLfloat newRotation)
{
    _rotation = newRotation;
}

Vec2 Entity::getVelocity()
{
    return _velocity;
}

void Entity::setVelocity(Vec2 newVelocity)
{
    _velocity = newVelocity;
}

Vec2 Entity::getScaleVelocity()
{
    return _scaleVelocity;
}

void Entity::setScaleVelocity(Vec2 newScaleVelocity)
{
    _scaleVelocity = newScaleVelocity;
}

GLfloat Entity::getRotationVelocity()
{
    return _rotationVelocity;
}

void Entity::setRotationVelocity(GLfloat newRotationVelocity)
{
    _rotationVelocity = newRotationVelocity;
}

Vec2 Entity::getEyeVector()
{
    return _eyeVector;
}

void Entity::setEyeVector(Vec2 newEyeVector)
{
    _eyeVector = newEyeVector;
}

Vec2 Entity::getUpVector()
{
    return _upVector;
}

void Entity::setUpVector(Vec2 newUpVector)
{
    _upVector = newUpVector;
}

int Entity::getNowAnimate_No()
{
	return this->_nowAnimate_No;
}

void Entity::setNowAnimate_No(int newNum)
{
	this->_nowAnimate_No = newNum;
}

Entity::Entity(Animator *newAnimator, Vec2 position):
_animator(newAnimator), _position(position),
_scale(Vec2(1.0f, 1.0f)), _rotation(GLfloat(0.0f)),
_velocity(Vec2(0.0f, 0.0f)), _scaleVelocity(Vec2(0.0f, 0.0f)),
_rotationVelocity(GLfloat(0.0f)), _eyeVector(Vec2(0.0f, 0.0f)),
_upVector(Vec2(0.0f, 1.0f))
{
}

Entity::~Entity()
{
    
}