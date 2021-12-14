#include "RenderSystem.h"


RenderSystem::RenderSystem() :_window(glfwGetCurrentContext())
{
	std::cout << "RenderSystem is created" << std::endl;
}


RenderSystem::~RenderSystem()
{
}

void RenderSystem::render(std::vector<Entity *> *entityArray, double deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	for (std::vector<Entity *>::iterator iterator = entityArray->begin(); iterator != entityArray->end(); iterator++) {

		Entity *entity = *iterator;
		if (entity->getAnimator() != NULL) {
			glLoadIdentity();

			glTranslatef(entity->getPosition().x, entity->getPosition().y,0);
			//glRotatef(entity->getRotation(), 0.0f, 0.0f, 1.0f);
			//glScalef(entity->getScale().x, entity->getScale().y, 1);		
			entity->getAnimator()->play(entity->getNowAnimate_No(),deltaTime);
		}


	}


	glfwSwapBuffers(_window);
	glfwPollEvents();
}


RenderSystem& RenderSystem::getRenderSystem()
{
	
	static RenderSystem *renderSystem = NULL;
	if (renderSystem == NULL) {
		renderSystem = new RenderSystem();
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glViewport(0, 0, 800 * 16 / 9, 800);

		glEnable(GL_TEXTURE_2D);

		glMatrixMode(GL_PROJECTION);
		glOrtho(0.0f, 800 * 16 / 9, 0.0f, 800, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_BLEND);
	}
	return *renderSystem;
}

void RenderSystem::destroyRenderSystem()
{
	RenderSystem *renderSystem = &RenderSystem::getRenderSystem();
	delete renderSystem;
}
