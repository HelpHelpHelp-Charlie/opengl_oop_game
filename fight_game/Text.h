#pragma once
#ifndef __FightGame__Text__
#define __FightGame__Text__

#include"AbstractUIComponent.h"

class Text :
	public AbstractUIComponent {
private:
protected:
public:
	Text() {
		//this->_position = Vec2(100, 100);
		this->imgName = "text.tga";
		//this->AnimationFrameData="timer.txt";
		this->HeightandWidth = Vec2(100, 150);
		this->autoMakeSprite(Vec2(0, 600), Vec4(128, 128, 12, 12), 144);
	}
	void setText(int num) {
		this->_sprite->setNowAnimate_No(num);
	}
};

#endif