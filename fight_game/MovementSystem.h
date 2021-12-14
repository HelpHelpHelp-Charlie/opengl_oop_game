#pragma once

#ifndef __SimpleFPS__MovementSystem__
#define __SimpleFPS__MovementSystem__

#include <iostream>
#include "Vec2.h"
#include <glfw3.h>
#include "Entity.h"

class MovementSystem
{
private:

	MovementSystem();
	~MovementSystem();

public:

	void update(std::vector<Entity *> *entityArray);

	static MovementSystem& getMovementSystem();
	static void destroyMovementSystem();
};


#endif
