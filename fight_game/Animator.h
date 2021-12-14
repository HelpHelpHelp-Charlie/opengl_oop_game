#pragma once
#ifndef  __FightGame__Animator__
#define __FightGame__Animator__
#include<vector>
#include"Animation2D.h"
class Animator {
private:
public:
	Animator();
	std::vector<Animation2D *> *_animation2DArray;
	void play(int animatio_no, double deltatime);
};

#endif