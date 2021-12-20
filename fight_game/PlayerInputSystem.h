
#ifndef __SimpleFPS__PlayerInputSystem__
#define __SimpleFPS__PlayerInputSystem__

#include <iostream>
#include  <glfw3.h>
#include<gl\GLUT.H>
#include "Entity.h"
#include "Vec2.h"
#include"Player.h"

class PlayerInputSystem
{
private:
	Vec2 _lastMousePosition;

	Vec2 _eyeVector;

	GLFWwindow *_window;

	Player *_currentPlayer;

	PlayerInputSystem();
	~PlayerInputSystem();

	void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

public:

	void setCurrentPlayer(Player *newPlayer);

	void update();

	static PlayerInputSystem& getPlayerInputSystem();
	static void destroyPlayerInputSystem();

	static void keyCallbackFun(GLFWwindow *window, int key, int scancode, int action, int mods);
};

#endif /* defined(__SimpleFPS__PlayerInputSystem__) */

