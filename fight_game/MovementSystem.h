#pragma once

#ifndef __SimpleFPS__MovementSystem__
#define __SimpleFPS__MovementSystem__

#include <iostream>
#include "Vec2.h"
#include <glfw3.h>
#include "Entity.h"
#include"Player.h"
class MovementSystem
{
private:

	MovementSystem();
	~MovementSystem();

public:

	void update(std::vector<Player *> *playerArray);

	static MovementSystem& getMovementSystem();
	static void destroyMovementSystem();
};


#endif
