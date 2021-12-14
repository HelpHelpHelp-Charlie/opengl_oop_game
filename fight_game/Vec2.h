#ifndef  __FightGame__Vec2__
#define __FightGame__Vec2__

#pragma once
#include<glfw3.h>
class Vec2 {
public:
	GLdouble x;
	GLdouble y;
	Vec2():x(0),y(0) {};
	Vec2(GLfloat x, GLfloat y) :x(x), y(y) {}
	Vec2 operator + (const Vec2&);

};

#endif