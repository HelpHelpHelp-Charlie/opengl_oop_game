#pragma once
#ifndef  __FightGame__Animator__
#define __FightGame__Animator__
#include<vector>
#include"Animation2D.h"
class Animator {
private:
	bool _visibility=true;
public:
	Animator();
	Animator(bool Visibility);
	void setVisibility(bool newVisibility);
	std::vector<Animation2D *> *_animation2DArray;
	void play(int animatio_no, double deltatime);
};

#endif