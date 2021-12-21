#pragma once
#ifndef __FightGame__HighLightSign__
#define __FightGame__HighLightSign__
#include"AbstractInteraction.h"
#include"Entity.h"
class HighLightSign :
	public AbstractInteraction{
private:
	Entity *_entity;
	
	Texture *_texture;
	std::vector<VertexBuffer *> *_vertexBufferArray;
	std::vector<Animator *>*_animatorArray;
	AbstractInteraction *_AbstractInteraction;

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
		cout << "[pppppppppppppppppppppppp" << endl;
		this->_entity = new Entity(this->_animatorArray->at(0), thisLocation);
	};

	Entity *getEntity() { return this->_entity; }


	void setVisibility(bool trigger) {	
		this->getEntity()->getAnimator()->setVisibility(false);
		if(trigger)this->getEntity()->getAnimator()->setVisibility(true);
	}

};
#endif // !__FightGame__HighLightSign__
