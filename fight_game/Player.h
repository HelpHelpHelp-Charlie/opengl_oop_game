#ifndef __FightGame__Player___
#define __FightGame__Player__

#pragma once
#include"Entity.h"
#include"GridMap.h"
#include<glfw3.h>
class Player {
private:
	Entity* _entity;	
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
public:
	const int playerWidth = 100;
	Player(Entity* e ,GridMap* gridmap) :	_position(Vec2(200, 200)),_scale(Vec2(1.0f, 1.0f)), _rotation(GLfloat(0.0f)),
		_velocity(Vec2(0.0f, 0.0f)), _scaleVelocity(Vec2(0.0f, 0.0f)),
		_rotationVelocity(GLfloat(0.0f)), _eyeVector(Vec2(0.0f, 0.0f)),
		_upVector(Vec2(0.0f, 1.0f)) {
		_entity = e; this->_gridmap = gridmap;
	}
	~Player();

	void update();

	Entity* getEntity() { return this->_entity; }
	void setEntity(Entity &entity) { this->_entity = &entity; }

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
};

#endif