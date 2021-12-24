#include "Player.h"

void Player::update()
{
	this->_position = this->_position +this->_velocity;
	this->_sprite->setPosition( Vec2(this->_position.x-this->playerWidth/2, this->_position.y- this->playerWidth / 2));
	this->_atGridTile=this->_gridmap->getGridLocationInMap(this->_position);
	//cout << _grabEntityID << endl;
	if (this->_isGrabingThing)this->_entityManager->getEntityArr()->at(this->_grabEntityID)->setPos(this->_position);
	//cout << _atGridTile<<endl;
}

Vec2 Player::getAtGridTile()
{
	return this->_atGridTile;
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
	return this->_sprite->getNowAnimate_No();
}

void Player::setNowAnimate_No(int newNum)
{
	this->_sprite->setNowAnimate_No(newNum);
}

bool Player::getGrabOrPlace()
{
	return this->_grabOrPlace;
}

void Player::setGrabOrPlace(bool newGrab)
{
	this->_grabOrPlace = newGrab;
}

bool Player::getIsGrabingThing()
{
	return this->_isGrabingThing;
}

void Player::setIsGrabingThing(bool isGrabing)
{
	this->_isGrabingThing = isGrabing;
}

int Player::getGrabEntityID()
{
	return this->_grabEntityID;
}

void Player::setGrabEntityID(int ID)
{
	this->_grabEntityID = ID;
}
