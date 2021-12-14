#ifndef  __FightGame__Entity__
#define __FightGame__Entity__

#include <iostream>
#include "VertexBuffer.h"
#include"Vec2.h"
#include <vector>
#include"Animation2D.h"
#include"Animator.h"

class Entity
{
private:

	Animator *_animator;
	int _nowAnimate_No;
 
	Vec2 _position;
	Vec2 _scale;
	GLfloat _rotation;
    
	Vec2 _velocity;
	Vec2 _scaleVelocity;
	GLfloat _rotationVelocity;
    
	Vec2 _eyeVector;
	Vec2 _upVector;
public:
    
	Animator *getAnimator();
    void setAnimator(Animator *newAnimator);
    
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

    Entity(Animator *newAnimation2D, Vec2 position);
    ~Entity();
};

#endif