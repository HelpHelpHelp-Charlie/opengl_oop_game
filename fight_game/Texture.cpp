#include "Texture.h"

Texture::Texture(const char * filename, Vec4 TextureCutSetting)
{
	_TextureCutSetting = TextureCutSetting;
	glGenTextures(1, &this->_textureBufferID);

	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD); // this is default
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, this->_textureBufferID);

	GLbyte *pImage = NULL;
	GLint iWidth, iHeight, iComponents;
	GLfloat myWidth, myHeight;
	GLenum eFormat;
	//glBindTexture(GL_TEXTURE_2D, textures[SHAPE_TEX]);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	pImage = gltLoadTGA(filename, &iWidth, &iHeight, &iComponents, &eFormat);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, iComponents, iWidth, iHeight, 0, eFormat, GL_UNSIGNED_BYTE, pImage);

	free(pImage);
}

void Texture::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D, this->_textureBufferID);
}
