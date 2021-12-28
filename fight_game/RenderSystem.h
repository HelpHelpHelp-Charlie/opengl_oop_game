
#ifndef  __FightGame__RenderSystem__
#define __FightGame__RenderSystem__

#include<iostream>
#include<glfw3.h>
//#include<gl\GLUT.H>
#include<glad\glad.h>
#include<vector>
#include"Sprite.h"
#include"GridMap.h"
#include"Entity.h"
#include"AbstractUIComponent.h"
#include"UIComponentManager.h"
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

	void render(GridMap* gridMap,std::vector<Sprite *> *spriteArray, std::vector<Entity *> *entityArray,UIComponentManager*_UI,double deltaTime);
	static RenderSystem& getRenderSystem();
	static void destroyRenderSystem();
};

#endif