#ifndef __FightGame__Player___
#define __FightGame__Player__

#pragma once
#include"Sprite.h"
#include"GridMap.h"
#include<glfw3.h>
#include"Entity.h"
#include"EntityManager.h"
class GridMap;
class Player {
private:
	Sprite* _sprite;
	Vec2 _position;
	Vec2 _scale;
	GLfloat _rotation;
	GridMap *_gridmap;
	
	Vec2 _velocity;
	Vec2 _scaleVelocity;
	GLfloat _rotationVelocity;

	Vec2 _atGridTile;
	Vec2 _lookatGridTile;
	Vec2 _eyeVector;
	Vec2 _upVector;

	bool _grabOrPlace;
	bool _isGrabingThing=false;
	int _grabEntityID=9;

	EntityManager*_entityManager;
public:
	const int playerWidth = 100;
	Player(Sprite* e ,GridMap* gridmap) :	_position(Vec2(200, 200)),_scale(Vec2(1.0f, 1.0f)), _rotation(GLfloat(0.0f)),
		_velocity(Vec2(0.0f, 0.0f)), _scaleVelocity(Vec2(0.0f, 0.0f)),
		_rotationVelocity(GLfloat(0.0f)), _eyeVector(Vec2(0.0f, 0.0f)),
		_upVector(Vec2(0.0f, 1.0f)) {
		_sprite = e; this->_gridmap = gridmap;
		this->_entityManager = &EntityManager::getEntityManager();
	}
	~Player();

	void update();


	Vec2 getAtGridTile();

	Sprite* getSprite() { return this->_sprite; }
	void setSprite(Sprite &sprite) { this->_sprite = &sprite; }

	Vec2 getPosition();
	void setPosition(Vec2 newPosition);

	Vec2 getScale();
	void setScale(Vec2 newScale);

	GLfloat getRotation();
	void setRotation(GLfloat newRotation);

	Vec2 getVelocity();
	void setVelocity(Vec2 newVelocity);

	Vec2 getScaleVelocity();
	void setScaleVelocity(Vec2 newScaleVelocity);

	GLfloat getRotationVelocity();
	void setRotationVelocity(GLfloat newRotationVelocity);

	Vec2 getEyeVector();
	void setEyeVector(Vec2 newEyeVector);

	Vec2 getUpVector();
	void setUpVector(Vec2 newUpVector);

	int getNowAnimate_No();
	void setNowAnimate_No(int newNum);

	bool getGrabOrPlace();
	void setGrabOrPlace(bool newGrab);


	bool getIsGrabingThing();
	void setIsGrabingThing(bool isGrabing);

	int getGrabEntityID();
	void setGrabEntityID(int ID);
};

#endif