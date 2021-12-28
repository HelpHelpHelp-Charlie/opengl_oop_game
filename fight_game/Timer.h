#pragma once
#ifndef __FightGame__Timer__
#define __FightGame__Timer__

#include"AbstractUIComponent.h"
#include"Text.h"
class Timer :
	public AbstractUIComponent {
private:
	Text* _text1;
	Text* _text2;
	Text* _text3;
	double totalTime = 30;
	double startTime;
protected:
public:
	Timer() {
		//this->_position = Vec2(100, 100);
		this->imgName = "timer.tga";
		//this->AnimationFrameData="timer.txt";
		this->HeightandWidth = Vec2(400, 200);
		this->autoMakeSprite(Vec2(400, 400), Vec4(256, 128, 5, 5), 24);
		this->getSprite()->setPosition(Vec2(0, 800));
		this->_text1 = new Text();
		this->_text2 = new Text();
		this->_text3 = new Text();
		this->_text1->getSprite()->setPosition(Vec2(this->getSprite()->getPosition().x + 70, this->getSprite()->getPosition().y + 30));
		this->_text2->getSprite()->setPosition(Vec2(this->getSprite()->getPosition().x + 200, this->getSprite()->getPosition().y + 30));
		this->_text3->getSprite()->setPosition(Vec2(this->getSprite()->getPosition().x + 280, this->getSprite()->getPosition().y + 30));
		this->startTime = glfwGetTime();
	}

	void draw(double deltaTime) {
		if (this->getSprite()->getAnimator() != NULL) {
			//glLoadIdentity();
			//glRotatef(sprite->getRotation(), 0.0f, 0.0f, 1.0f);
			//glScalef(sprite->getScale().x, sprite->getScale().y, 1);	
			glLoadIdentity();
			glTranslatef(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y, 0);
			this->getSprite()->getAnimator()->play(this->getSprite()->getNowAnimate_No(), deltaTime);


			glLoadIdentity();
			glTranslatef(this->_text1->getSprite()->getPosition().x, this->_text1->getSprite()->getPosition().y, 0);
			this->_text1->getSprite()->getAnimator()->play(this->_text1->getSprite()->getNowAnimate_No(), deltaTime);

			glLoadIdentity();
			glTranslatef(this->_text2->getSprite()->getPosition().x, this->_text2->getSprite()->getPosition().y, 0);
			this->_text2->getSprite()->getAnimator()->play(this->_text2->getSprite()->getNowAnimate_No(), deltaTime);

			glLoadIdentity();
			glTranslatef(this->_text3->getSprite()->getPosition().x, this->_text3->getSprite()->getPosition().y, 0);
			this->_text3->getSprite()->getAnimator()->play(this->_text3->getSprite()->getNowAnimate_No(), deltaTime);
		}
	}

	void update() {
		double passedTime = (glfwGetTime() - startTime);
		double restTime = totalTime - passedTime;
		if (restTime > 0) {
			this->_text1->setText(int(restTime / 60));
			this->_text2->setText(int(int(int(restTime) % 60)) / 10);
			this->_text3->setText(int(int(int(restTime) % 60)) % 10);
			this->_sprite->setNowAnimate_No(int((passedTime / totalTime) * 24));
		}

	}
};

#endif