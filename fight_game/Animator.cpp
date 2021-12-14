#include "Animator.h"

Animator::Animator()
{
	_animation2DArray = new std::vector<Animation2D *>;
}

void Animator::play(int animatio_no , double deltatime)
{
	_animation2DArray->at(animatio_no)->play(deltatime);
}
