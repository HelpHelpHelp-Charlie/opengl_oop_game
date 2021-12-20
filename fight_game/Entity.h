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
	Vec2 _position;
	Animator *_animator;
	int _nowAnimate_No;
 

public:
    
	Animator *getAnimator();
    void setAnimator(Animator *newAnimator);
 
	Vec2 getPosition();
	void setPosition(Vec2 newPosition);

	int getNowAnimate_No();
	void setNowAnimate_No(int newNum);

	Entity();
    Entity(Animator *newAnimation2D, Vec2 position);
    ~Entity();
};

#endif