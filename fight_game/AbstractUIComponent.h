#pragma once
#ifndef __FightGame__AbstractUIComponent__
#define __FightGame__AbstractUIComponent__
#include"Vec2.h"
#include"Sprite.h"

class AbstractUIComponent {
private:
protected:
	bool enable;
	Sprite* _sprite;	
	Vec2 HeightandWidth;
	std::string imgName = "Ingredient.tga";
	std::string AnimationFrameData;
public:
	Sprite* getSprite();
	void autoMakeSprite(Vec2 pos, Vec4 textureSetting,int frameNum) {
		Texture *texture;
		std::vector<VertexBuffer *> *vertexBufferArray;
		std::vector<Animator *>*animatorArray;

		vertexBufferArray = new std::vector<VertexBuffer *>();
		animatorArray = new std::vector<Animator *>();
		const char * a = this->imgName.c_str();
		texture = new Texture(a, textureSetting);

		Animator *player = new Animator();
		animatorArray->push_back(player);
		//const char * b = this->AnimationFrameData.c_str();


		for (int i = 0; i < frameNum; i++) {	
			Animation2D *temp = new Animation2D(Vec4(i%int(textureSetting.z)* textureSetting.x,(int (i/int(textureSetting.z))+1)* textureSetting.y, textureSetting.x, textureSetting.y), 30);
			animatorArray->at(0)->_animation2DArray->push_back(temp);
		}

		int animation2DCounter = 0;
		std::vector<Vec4*> *normalizeFrames = new std::vector<Vec4*>;
		for (std::vector<Animation2D*>::iterator animatorIterator = animatorArray->at(0)->_animation2DArray->begin();
			animatorIterator != animatorArray->at(0)->_animation2DArray->end(); animatorIterator++) {

			normalizeFrames = animatorArray->at(0)->_animation2DArray->at(animation2DCounter)->getNormallizeFramesArray(texture->getTextureCutSetting());


			int normalizeFrameCounter = 0;
			vertexBufferArray = new std::vector<VertexBuffer *>();
			for (std::vector<Vec4*>::iterator iterator = normalizeFrames->begin(); iterator != normalizeFrames->end(); iterator++) {
				VertexData vertices[4] = {
					{ { 0,0,0 },{ normalizeFrames->at(normalizeFrameCounter)->x,normalizeFrames->at(normalizeFrameCounter)->y } },
					{ { this->HeightandWidth.x,0,0 },{ normalizeFrames->at(normalizeFrameCounter)->x + normalizeFrames->at(normalizeFrameCounter)->z,normalizeFrames->at(normalizeFrameCounter)->y } },
					{ { this->HeightandWidth.x,this->HeightandWidth.y,0 },{ normalizeFrames->at(normalizeFrameCounter)->x + normalizeFrames->at(normalizeFrameCounter)->z,normalizeFrames->at(normalizeFrameCounter)->y - normalizeFrames->at(normalizeFrameCounter)->w } },
					{ { 0,this->HeightandWidth.y,0 },{ normalizeFrames->at(normalizeFrameCounter)->x, normalizeFrames->at(normalizeFrameCounter)->y - normalizeFrames->at(normalizeFrameCounter)->w } }
				};
				normalizeFrameCounter++;
				VertexBuffer *vertexBuffer = new VertexBuffer(
					vertices,
					sizeof(vertices),
					GL_QUADS,
					4,
					sizeof(VertexData),
					texture,
					(GLvoid*)offsetof(VertexData, positionCoordinates),
					(GLvoid*)offsetof(VertexData, textureCoordinates));
				vertexBufferArray->push_back(vertexBuffer);
			}

			animatorArray->at(0)->_animation2DArray->at(animation2DCounter)->setvertexBufferArray(vertexBufferArray);
			animation2DCounter++;
		}

		this->_sprite = new Sprite(animatorArray->at(0), pos);
	};
	virtual void draw(double deltaTime) {
		if (this->getSprite()->getAnimator() != NULL) {
			//glLoadIdentity();
			//glRotatef(sprite->getRotation(), 0.0f, 0.0f, 1.0f);
			//glScalef(sprite->getScale().x, sprite->getScale().y, 1);	
			glLoadIdentity();
			glTranslatef(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y, 0);
			this->getSprite()->getAnimator()->play(this->getSprite()->getNowAnimate_No(), deltaTime);
		}
	}

	virtual void update() {};
};

#endif