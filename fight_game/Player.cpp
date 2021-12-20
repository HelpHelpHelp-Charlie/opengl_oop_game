#include "Player.h"

void Player::update()
{
	this->_position = this->_position +this->_velocity;
	this->_entity->setPosition(this->_position);

}


Vec2 Player::getPosition()
{
	return _position;
}

void Player::setPosition(Vec2 newPosition)
{
	_position = newPosition;
}

Vec2 Player::getScale()
{
	return _scale;
}

void Player::setScale(Vec2 newScale)
{
	_scale = newScale;
}

GLfloat Player::getRotation()
{
	return _rotation;
}

void Player::setRotation(GLfloat newRotation)
{
	_rotation = newRotation;
}

Vec2 Player::getVelocity()
{
	return _velocity;
}

void Player::setVelocity(Vec2 newVelocity)
{
	_velocity = newVelocity;
}

Vec2 Player::getScaleVelocity()
{
	return _scaleVelocity;
}

void Player::setScaleVelocity(Vec2 newScaleVelocity)
{
	_scaleVelocity = newScaleVelocity;
}

GLfloat Player::getRotationVelocity()
{
	return _rotationVelocity;
}

void Player::setRotationVelocity(GLfloat newRotationVelocity)
{
	_rotationVelocity = newRotationVelocity;
}

Vec2 Player::getEyeVector()
{
	return _eyeVector;
}

void Player::setEyeVector(Vec2 newEyeVector)
{
	_eyeVector = newEyeVector;
}

Vec2 Player::getUpVector()
{
	return _upVector;
}

void Player::setUpVector(Vec2 newUpVector)
{
	_upVector = newUpVector;
}

int Player::getNowAnimate_No()
{
	return this->_entity->getNowAnimate_No();
}

void Player::setNowAnimate_No(int newNum)
{
	this->_entity->setNowAnimate_No(newNum);
}
