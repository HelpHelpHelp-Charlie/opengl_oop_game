#include "Animator.h"



Animator::Animator()
{
	this->_visibility = true;
	this->_animation2DArray = new std::vector<Animation2D *>();
}

Animator::Animator(bool newVisibility)
{
	this->_visibility = newVisibility;
	this->_animation2DArray = new std::vector<Animation2D *>();
}

void Animator::setVisibility(bool newVisibility)
{
	this->_visibility = newVisibility;
}

void Animator::play(int animation_no, double deltatime)
{
	if (this->_visibility) {
		_animation2DArray->at(animation_no)->play(deltatime);
	}

	//_animation2DArray->at(0)->play(deltatime);
}
