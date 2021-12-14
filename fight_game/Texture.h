#ifndef  __FightGame__Texture__
#define __FightGame__Texture__

#pragma once
#include<glfw3.h>
#include<glad\glad.h>
#include"loadTGA.h"
#include"Vec4.h"

class Texture {
private:
	GLuint _textureBufferID;
	Vec4 _TextureCutSetting;
	unsigned int type;
	GLint textureUnit;
public:
	Texture(const char* filename,Vec4 TextureCutSetting);
	int width;
	int height;
	inline GLuint getID() const { return this->_textureBufferID; }
	inline Vec4 getTextureCutSetting() const { return this->_TextureCutSetting; }
	void bindTexture();
};


#endif