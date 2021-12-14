//
//  VertexBuffer.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 12/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "VertexBuffer.h"

GLuint VertexBuffer::getVertexBufferID()
{
    return _vertexBufferID;
}


VertexBuffer::VertexBuffer(const GLvoid *data,
							GLsizei size,
                           GLenum mode,
                           GLsizei count,
							GLsizei stride,
							Texture *texture,
                           GLvoid *positionOffset,
                           GLvoid *textureOffset):
_mode(mode), _count(count), _stride(stride),_texture(texture), _positionOffset(positionOffset), _textureOffset(textureOffset)
{
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, _stride, _positionOffset);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, _stride, _textureOffset);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &_vertexBufferID);
    _vertexBufferID = 0;
}

void VertexBuffer::configureVertexAttributes()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, _stride, _positionOffset);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, _stride, _textureOffset);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
	_texture->bindTexture();
}

void VertexBuffer::renderVertexBuffer()
{
    glDrawArrays(GL_QUADS, 0, _count);
	
}
