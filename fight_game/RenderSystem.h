
#ifndef  __FightGame__RenderSystem__
#define __FightGame__RenderSystem__

#include<iostream>
#include<glfw3.h>
#include<gl\GLUT.H>
#include<glad\glad.h>
#include<vector>
#include"Entity.h"
#include"GridMap.h"
//#pragma comment(lib,"glew32.lib")
#pragma comment(lib,"glfw3.lib")
class RenderSystem {
private:
	GLFWwindow *_window;
	GLfloat _height;
	GLfloat _width;	
	RenderSystem();
	~RenderSystem();
public :

	void render(GridMap* gridMap,std::vector<Entity *> *entityArray, double deltaTime);
	static RenderSystem& getRenderSystem();
	static void destroyRenderSystem();
};

#endif