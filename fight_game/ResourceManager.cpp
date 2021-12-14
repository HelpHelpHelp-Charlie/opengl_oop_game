#include "ResourceManager.h"


std::vector<Texture*>* ResourceManager::getTextureArray()
{
	return _textureArray;
}

std::vector<VertexBuffer *>* ResourceManager::getVertexBufferArray()
{
	return _vertexBufferArray;
}

std::vector<Animator*>* ResourceManager::getAnimatorArray()
{
	return _animatorArray;
}

void ResourceManager::objectAnimator(int object_no) {

	int animation2DCounter = 0;
	std::vector<Vec4*> *normalizeFrames = new std::vector<Vec4*>;
	for (std::vector<Animation2D*>::iterator animatorIterator = _animatorArray->at(object_no)->_animation2DArray->begin();
		animatorIterator != _animatorArray->at(object_no)->_animation2DArray->end(); animatorIterator++) {

		normalizeFrames = _animatorArray->at(object_no)->_animation2DArray->at(animation2DCounter)->getNormallizeFramesArray(_textureArray->at(object_no)->getTextureCutSetting());


		int normalizeFrameCounter = 0;
		_vertexBufferArray = new std::vector<VertexBuffer *>();
		for (std::vector<Vec4*>::iterator iterator = normalizeFrames->begin(); iterator != normalizeFrames->end(); iterator++) {

			VertexData vertices[4] = {
				{ { 0,0,0 },{ normalizeFrames->at(normalizeFrameCounter)->x,normalizeFrames->at(normalizeFrameCounter)->y } },
				{ { 96 * 3,0,0 },{ normalizeFrames->at(normalizeFrameCounter)->x + normalizeFrames->at(normalizeFrameCounter)->z,normalizeFrames->at(normalizeFrameCounter)->y } },
				{ { 96 * 3,104 * 3,0 },{ normalizeFrames->at(normalizeFrameCounter)->x + normalizeFrames->at(normalizeFrameCounter)->z,normalizeFrames->at(normalizeFrameCounter)->y - normalizeFrames->at(normalizeFrameCounter)->w } },
				{ { 0,104 * 3,0 },{ normalizeFrames->at(normalizeFrameCounter)->x, normalizeFrames->at(normalizeFrameCounter)->y - normalizeFrames->at(normalizeFrameCounter)->w } }
			};
			normalizeFrameCounter++;
			VertexBuffer *vertexBuffer = new VertexBuffer(
				vertices,
				sizeof(vertices),
				GL_QUADS,
				4,
				sizeof(VertexData),
				_textureArray->at(object_no),
				(GLvoid*)offsetof(VertexData, positionCoordinates),
				(GLvoid*)offsetof(VertexData, textureCoordinates));
			_vertexBufferArray->push_back(vertexBuffer);
		}

		_animatorArray->at(object_no)->_animation2DArray->at(animation2DCounter)->setvertexBufferArray(_vertexBufferArray);
		animation2DCounter++;
	}
}

ResourceManager::ResourceManager()
{

	std::cout << "ResourceManager is created" << std::endl;

	_textureArray = new std::vector<Texture *>();
	Texture *Texture_Shark = new Texture("player.tga", Vec4(96, 104, 8, 10));
	_textureArray->push_back(Texture_Shark);

	_animatorArray = new std::vector<Animator *>();

	Animator *player = new Animator();
	_animatorArray->push_back(player);


	Animation2D *up_run = new Animation2D("up_run.txt", 30);
	Animation2D *idle_up = new Animation2D("idle_up.txt", 150);
	Animation2D *down_run = new Animation2D("down_run.txt", 30);
	Animation2D *idle_down = new Animation2D("idle_down.txt", 150);
	Animation2D *left_run = new Animation2D("left_run.txt", 30);
	Animation2D *idle_left = new Animation2D("idle_left.txt", 150);
	Animation2D *right_run = new Animation2D("right_run.txt", 30);
	Animation2D *idle_right = new Animation2D("idle_right.txt", 150);



	_animatorArray->at(0)->_animation2DArray->push_back(up_run);
	_animatorArray->at(0)->_animation2DArray->push_back(idle_up);
	_animatorArray->at(0)->_animation2DArray->push_back(down_run);
	_animatorArray->at(0)->_animation2DArray->push_back(idle_down);
	_animatorArray->at(0)->_animation2DArray->push_back(left_run);
	_animatorArray->at(0)->_animation2DArray->push_back(idle_left);
	_animatorArray->at(0)->_animation2DArray->push_back(right_run);
	_animatorArray->at(0)->_animation2DArray->push_back(idle_right);

	objectAnimator(0);
}

ResourceManager::~ResourceManager()
{
	for (std::vector<VertexBuffer *>::iterator iterator = _vertexBufferArray->begin();
		iterator != _vertexBufferArray->end();
		iterator++) {
		delete *iterator;
	}

	delete _vertexBufferArray;
}

ResourceManager& ResourceManager::getResourceManager()
{
	static ResourceManager *resourceManager = NULL;

	if (resourceManager == NULL) {
		resourceManager = new ResourceManager();
	}

	return *resourceManager;
}

void ResourceManager::destroyResourceManager()
{
	ResourceManager *resourceManager = &getResourceManager();
	delete resourceManager;
}

