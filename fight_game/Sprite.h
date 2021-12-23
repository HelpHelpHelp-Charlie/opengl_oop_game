#ifndef  __FightGame__Sprite__
#define __FightGame__Sprite__

#include <iostream>
#include "VertexBuffer.h"
#include"Vec2.h"
#include <vector>
#include"Animation2D.h"
#include"Animator.h"

class Sprite
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

	Sprite();
    Sprite(Animator *newAnimation2D, Vec2 position);
    ~Sprite();
};

#endif