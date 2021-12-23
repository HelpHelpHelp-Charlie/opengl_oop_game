#include "Entity.h"


void Entity::makeSprite(Vec2 pos, Vec4 textureSetting)
{
	Texture *texture;
	std::vector<VertexBuffer *> *vertexBufferArray;
	std::vector<Animator *>*animatorArray;

	vertexBufferArray = new std::vector<VertexBuffer *>();
	animatorArray = new std::vector<Animator *>();
	const char * a = this->imgName.c_str();
	texture = new Texture(a, textureSetting);

	Animator *player = new Animator();
	animatorArray->push_back(player);
	Animation2D *MeatBox_idle = new Animation2D(this->AnimationFrameData, 30);
	//Animation2D *idle_up = new Animation2D("idle_up.txt", 150);
	animatorArray->at(0)->_animation2DArray->push_back(MeatBox_idle);
	//this->_animator->_animation2DArray->push_back(idle_up);


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
				texture,
				(GLvoid*)offsetof(VertexData, positionCoordinates),
				(GLvoid*)offsetof(VertexData, textureCoordinates));
			vertexBufferArray->push_back(vertexBuffer);
		}

		animatorArray->at(0)->_animation2DArray->at(animation2DCounter)->setvertexBufferArray(vertexBufferArray);
		cout << animatorArray->at(0)->_animation2DArray << endl;

		animation2DCounter++;
	}

	this->_sprite = new Sprite(animatorArray->at(0), pos);
}

void Entity::setID(int newID)
{
	this->_id_InTheScene;
}

int Entity::getID()
{
	return this->_id_InTheScene;
}

Sprite * Entity::getSprite()
{
	return this->_sprite;
}
