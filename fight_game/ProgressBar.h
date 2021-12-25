#pragma once
#ifndef __FightGame__ProgressBar__
#define __FightGame__ProgressBar__
#include"AbstractInteraction.h"
#include "Tile.h"
class ProgressBar :
	public AbstractInteraction {
private:
	EntityManager *_entityManager;
	Sprite *_sprite;
	Texture *_texture;
	std::vector<VertexBuffer *> *_vertexBufferArray;
	std::vector<Animator *>*_animatorArray;

	int _needTime;
	float _startTime;
	float _nowUseTime;
	int progress;//0~12
	bool startCook = false;
	bool autoCook = false;
public:
	ProgressBar(Vec2 thisLocation, int needTime) :_needTime(needTime) {
		this->_vertexBufferArray = new std::vector<VertexBuffer *>();
		this->_animatorArray = new std::vector<Animator *>();

		this->_texture = new Texture("bar.tga", Vec4(128, 128, 16, 1));

		Animator *player = new Animator();//false
		this->_animatorArray->push_back(player);

		Animation2D *Animation1 = new Animation2D(Vec4(0, 128, 128, 128), 100);
		Animation2D *Animation2 = new Animation2D(Vec4(0, 256, 128, 128), 100);
		Animation2D *Animation3 = new Animation2D(Vec4(0, 384, 128, 128), 100);
		Animation2D *Animation4 = new Animation2D(Vec4(0, 512, 128, 128), 100);
		Animation2D *Animation5 = new Animation2D(Vec4(0, 640, 128, 128), 100);
		Animation2D *Animation6 = new Animation2D(Vec4(0, 768, 128, 128), 100);
		Animation2D *Animation7 = new Animation2D(Vec4(0, 896, 128, 128), 100);
		Animation2D *Animation8 = new Animation2D(Vec4(0, 1024, 128, 128), 100);
		Animation2D *Animation9 = new Animation2D(Vec4(0, 1152, 128, 128), 100);
		Animation2D *Animation10 = new Animation2D(Vec4(0, 1280, 128, 128), 100);
		Animation2D *Animation11 = new Animation2D(Vec4(0, 1408, 128, 128), 100);
		Animation2D *Animation12 = new Animation2D(Vec4(0, 1536, 128, 128), 100);
		Animation2D *Animation13 = new Animation2D(Vec4(0, 1664, 128, 128), 100);
		Animation2D *Animation14 = new Animation2D(Vec4(0, 1664+128+128 + 128, 128, 128), 100);

		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation1);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation2);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation3);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation4);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation5);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation6);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation7);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation8);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation9);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation10);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation11);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation12);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation13);
		this->_animatorArray->at(0)->_animation2DArray->push_back(Animation14);


		int animation2DCounter = 0;
		std::vector<Vec4*> *normalizeFrames = new std::vector<Vec4*>;
		for (std::vector<Animation2D*>::iterator animatorIterator = this->_animatorArray->at(0)->_animation2DArray->begin();
			animatorIterator != this->_animatorArray->at(0)->_animation2DArray->end(); animatorIterator++) {

			normalizeFrames = this->_animatorArray->at(0)->_animation2DArray->at(animation2DCounter)->getNormallizeFramesArray(this->_texture->getTextureCutSetting());


			int normalizeFrameCounter = 0;
			_vertexBufferArray = new std::vector<VertexBuffer *>();
			for (std::vector<Vec4*>::iterator iterator = normalizeFrames->begin(); iterator != normalizeFrames->end(); iterator++) {
				VertexData vertices[4] = {
					{ { 0,0,0 },{ normalizeFrames->at(normalizeFrameCounter)->x,normalizeFrames->at(normalizeFrameCounter)->y } },
					{ { 100,0,0 },{ normalizeFrames->at(normalizeFrameCounter)->x + normalizeFrames->at(normalizeFrameCounter)->z,normalizeFrames->at(normalizeFrameCounter)->y } },
					{ { 100,100,0 },{ normalizeFrames->at(normalizeFrameCounter)->x + normalizeFrames->at(normalizeFrameCounter)->z,normalizeFrames->at(normalizeFrameCounter)->y - normalizeFrames->at(normalizeFrameCounter)->w } },
					{ { 0,100,0 },{ normalizeFrames->at(normalizeFrameCounter)->x, normalizeFrames->at(normalizeFrameCounter)->y - normalizeFrames->at(normalizeFrameCounter)->w } }
				};
				normalizeFrameCounter++;
				VertexBuffer *vertexBuffer = new VertexBuffer(
					vertices,
					sizeof(vertices),
					GL_QUADS,
					4,
					sizeof(VertexData),
					this->_texture,
					(GLvoid*)offsetof(VertexData, positionCoordinates),
					(GLvoid*)offsetof(VertexData, textureCoordinates));
				_vertexBufferArray->push_back(vertexBuffer);
			}

			this->_animatorArray->at(0)->_animation2DArray->at(animation2DCounter)->setvertexBufferArray(_vertexBufferArray);
			cout << this->_animatorArray->at(0)->_animation2DArray << endl;

			animation2DCounter++;
		}
		this->_sprite = new Sprite(this->_animatorArray->at(0), thisLocation);
	};
	//bool Input(bool trigger, Player* player, Tile* tile);

	Sprite *getSprite() { return this->_sprite; }

	bool getStartCook() { return this->startCook; }
	void setStartCook(bool u) { this->startCook = u; }

	bool onuse() {
		if (this->enable) {
			this->getSprite()->getAnimator()->setVisibility(true);
			if (!autoCook) {
				_startTime = glfwGetTime(); autoCook = true;
			}
			_nowUseTime = glfwGetTime() - _startTime;
			this->_sprite->setNowAnimate_No(int((_nowUseTime / _needTime) * 12));
			cout << int((_nowUseTime / _needTime) * 12) << endl;

			if ((_nowUseTime / _needTime) >= 1) {
				autoCook = false;
				enable = false;
				return true;
			}
			return false;
		}
		return false;
	}

	void show() {
		this->getSprite()->getAnimator()->setVisibility(true);
		this->getSprite()->setNowAnimate_No(13);
	}

	void notShow() {
		this->getSprite()->getAnimator()->setVisibility(false);
	}
};
#endif