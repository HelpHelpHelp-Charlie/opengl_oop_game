#pragma once
#ifndef  __FightGame__Vec4__
#define __FightGame__Vec4__
class Vec4 {
public:
	Vec4() {};
	Vec4(float x, float y, float z, float w) :x(x), y(y), z(z), w(w) {};
	float x, y, z, w;
};

#endif
