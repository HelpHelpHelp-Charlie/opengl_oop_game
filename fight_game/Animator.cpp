#include "Animator.h"

Animator::Animator()
{
	this->_animation2DArray = new std::vector<Animation2D *>();
}
	
void Animator::play(int animation_no , double deltatime)
{
		_animation2DArray->at(animation_no)->play(deltatime);
	//_animation2DArray->at(0)->play(deltatime);
}
		