#pragma once
#include<glfw3.h>
#include<vector>
#include <string>
#include <sstream>
#include"VertexBuffer.h"
#include"Vec4.h"
#include"VertexData.h"
using namespace std;
#ifndef  __FightGame__Animation2D__
#define __FightGame__Animation2D__

class Animation2D
{
public:
	Animation2D(const char* filename,float speed);
	Animation2D(Vec4 newframe, float speed);
	~Animation2D();

	std::vector<Vec4 *>* getNormallizeFramesArray(Vec4 TextureCutSetting);
	void setvertexBufferArray(std::vector<VertexBuffer *>*vertexBufferArray);
	void play(double deltatime);

	//void play(Texture& spritetexture, Rectangle& rectangle, double deltatime);
	//void set_animation_speed(float newspeed);
	void setCurrentFrameIndex(int f) {this->current_frame_indx=f; }
	int getCurrentFrameIndex() {return this->current_frame_indx;}
private:
	std::vector<VertexBuffer *> *_vertexBufferArray;
	double anim_cursor;
	int current_frame_indx;
	int frames_count;
	float speed;


	vector<Vec4*>* _frames;
	vector<Vec4*>* _normalizeFrames;
};
#endif