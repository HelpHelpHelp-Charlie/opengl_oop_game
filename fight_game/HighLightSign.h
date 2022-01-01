#pragma once
#ifndef __FightGame__HighLightSign__
#define __FightGame__HighLightSign__
#include"AbstractInteraction.h"
#include"Sprite.h"
class HighLightSign :
	public AbstractInteraction{
private:
	Sprite *_sprite;
	
	Texture *_texture;
	std::vector<VertexBuffer *> *_vertexBufferArray;
	std::vector<Animator *>*_animatorArray;

public:
	HighLightSign(Vec2 thisLocation){
		this->_vertexBufferArray = new std::vector<VertexBuffer *>();
		this->_animatorArray = new std::vector<Animator *>();

		this->_texture = new Texture("selectSign.tga", Vec4(128, 128, 2, 1));

		Animator *player = new Animator();//false
		this->_animatorArray->push_back(player);

		Animation2D *selectSign = new Animation2D("selectSign.txt", 100);
		this->_animatorArray->at(0)->_animation2DArray->push_back(selectSign);


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
					{ { 150,0,0 },{ normalizeFrames->at(normalizeFrameCounter)->x + normalizeFrames->at(normalizeFrameCounter)->z,normalizeFrames->at(normalizeFrameCounter)->y } },
					{ { 150,150,0 },{ normalizeFrames->at(normalizeFrameCounter)->x + normalizeFrames->at(normalizeFrameCounter)->z,normalizeFrames->at(normalizeFrameCounter)->y - normalizeFrames->at(normalizeFrameCounter)->w } },
					{ { 0,150,0 },{ normalizeFrames->at(normalizeFrameCounter)->x, normalizeFrames->at(normalizeFrameCounter)->y - normalizeFrames->at(normalizeFrameCounter)->w } }
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

			animation2DCounter++;
		}
		this->_sprite = new Sprite(this->_animatorArray->at(0), thisLocation);
	};

	Sprite *getSprite() { return this->_sprite; }


	void setVisibility(bool trigger) {	
		this->getSprite()->getAnimator()->setVisibility(false);
		if(trigger)this->getSprite()->getAnimator()->setVisibility(true);
	}

};
#endif // !__FightGame__HighLightSign__
