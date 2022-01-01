#pragma once
#ifndef __FightGame__ScoreBoard__
#define __FightGame__ScoreBoard__

#include"AbstractUIComponent.h"
#include"Text.h"
class ScoreBoard :
	public AbstractUIComponent {
private:
	Text* _text1;
	Text* _text2;
	Text* _text3;
	float _score = 0;
	float _goal = 500;
protected:
public:
	ScoreBoard() {
		//this->_position = Vec2(100, 100);
		this->imgName = "score.tga";
		//this->AnimationFrameData="timer.txt";
		this->HeightandWidth = Vec2(370, 140);
		this->autoMakeSprite(Vec2(400, 400), Vec4(256, 128, 17, 1), 17);
		this->getSprite()->setPosition(Vec2(10, 750));
		this->_text1 = new Text();
		this->_text2 = new Text();
		this->_text3 = new Text();
		this->_text1->getSprite()->setPosition(Vec2(this->getSprite()->getPosition().x + 130, this->getSprite()->getPosition().y + 10));
		this->_text2->getSprite()->setPosition(Vec2(this->getSprite()->getPosition().x + 190, this->getSprite()->getPosition().y + 10));
		this->_text3->getSprite()->setPosition(Vec2(this->getSprite()->getPosition().x + 250, this->getSprite()->getPosition().y + 10));

	}
	void setScore(int score) {
		this->_score = score; 
	}
	int  getScore() { return this->_score; }
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
		this->_text1->setText(int(this->_score/100));
		this->_text2->setText(int((int(this->_score)%100) / 10));
		this->_text3->setText(int((int(this->_score) % 10) ));

		if (this->_score >= this->_goal) {
			this->_sprite->setNowAnimate_No(16);
		}
		this->_sprite->setNowAnimate_No(int((this->_score / this->_goal )*16));
	}


};

#endif