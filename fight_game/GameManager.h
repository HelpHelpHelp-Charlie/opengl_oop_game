#ifndef  __FightGame__GameManager__
#define __FightGame__GameManager__
#include<iostream>
#include<glfw3.h>
#include<glad\glad.h>
#include"RenderSystem.h"
#include"ResourceManager.h"
#include"PlayerInputSystem.h"
#include"MovementSystem.h"
#include "Entity.h"
#include "Scene.h"
#define Update_per_second 60
#pragma comment(lib,"glfw3.lib")
class GameManager {
private:
	bool _running;
	RenderSystem *_renderSystem;
	ResourceManager *_resourceManager;
	PlayerInputSystem *_playerInputSystem;
	MovementSystem *_movementSystem;
	GLFWwindow *_window;
	Scene *scene;
	GameManager(bool running);
	~GameManager();
public:
	void runGameLoop();	
	static GameManager& getGameManager();
	static void destroyGameManager();



};

#endif