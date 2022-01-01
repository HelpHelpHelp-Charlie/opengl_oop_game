#pragma once
#ifndef  __FightGame__FormerBuilder__
#define __FightGame__FormerBuilder__

#include"TileBuilder.h"
class FormerBuilder :
	public TileBuilder
{
private:

public:
	Tile* getResult(Vec2 pos) {

		this->_vertexBufferArray = new std::vector<VertexBuffer *>();
		this->_animatorArray = new std::vector<Animator *>();

		this->_texture = new Texture("forming.tga", Vec4(128, 128, 5, 5));
		//this->_texture = new Texture("Ingredient.tga", Vec4(128, 128, 9, 1));

		Animator *player = new Animator();
		this->_animatorArray->push_back(player);
		Animation2D *MeatBox_idle = new Animation2D("MeatBox_idle.txt", 30);
		Animation2D *forming_using = new Animation2D("forming_using.txt", 20);
		//Animation2D *MeatBox_idle = new Animation2D(Vec4(0, 256, 128, 128), 30);
		//Animation2D *idle_up = new Animation2D("idle_up.txt", 150);
		this->_animatorArray->at(0)->_animation2DArray->push_back(MeatBox_idle);
		this->_animatorArray->at(0)->_animation2DArray->push_back(forming_using);
		//this->_animator->_animation2DArray->push_back(idle_up);

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

		Sprite *m_sprite = new Sprite(this->_animatorArray->at(0), pos);
		Tile *_tile = new Former(m_sprite);

		return _tile;
	}


	~FormerBuilder() {}

};



#endif