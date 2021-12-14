#ifndef  __FightGame__VertexBuffer__
#define __FightGame__VertexBuffer__

#include <iostream>
#include <glfw3.h>
#include<gl\GLUT.H>
#include<glad\glad.h>
#include"Texture.h"
#include"VertexData.h"

class VertexBuffer
{
private:
    
    GLuint _vertexBufferID;    
    GLenum _mode;
    GLsizei _count;
    GLsizei _stride;
	Texture* _texture;
    GLvoid *_positionOffset;
	GLvoid *_textureOffset;
public:
    
    GLuint getVertexBufferID();
    VertexBuffer(const GLvoid *data,
				GLsizei size,
                 GLenum mode,
                 GLsizei count,
				GLsizei stride,
				Texture *texture,
                 GLvoid *positionOffset,
				GLvoid *textureOffset);
    ~VertexBuffer();
  
    void configureVertexAttributes();
    void renderVertexBuffer();
};

#endif