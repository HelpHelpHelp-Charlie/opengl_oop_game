#pragma once


#ifndef  __FightGame__Rect__
#define __FightGame__Rect__
#include<glfw3.h>
typedef struct Rect {
	GLdouble x;
	GLdouble y;
	GLdouble w;
	GLdouble h;
	Rect(GLdouble x, GLdouble y, GLdouble w, GLdouble h) :x(x), y(y), w(w), h(h) {};
}Rect;
#endif