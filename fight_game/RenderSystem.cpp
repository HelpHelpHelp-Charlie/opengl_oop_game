#include "RenderSystem.h"


RenderSystem::RenderSystem() :_window(glfwGetCurrentContext())
{
	std::cout << "RenderSystem is created" << std::endl;
}


RenderSystem::~RenderSystem()
{

}

void RenderSystem::render(GridMap* gridMap,std::vector<Sprite *> *spriteArray, std::vector<Entity *> *entityArray,double deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	gridMap->drawMap(deltaTime);	
int i = 0;
	for (std::vector<Sprite *>::iterator iterator = spriteArray->begin(); iterator != spriteArray->end(); iterator++) {
		i++;
		Sprite *sprite = *iterator;
		if (sprite->getAnimator() != NULL) {
			glLoadIdentity();
			glTranslatef(sprite->getPosition().x, sprite->getPosition().y,0);
			//glRotatef(sprite->getRotation(), 0.0f, 0.0f, 1.0f);
			//glScalef(sprite->getScale().x, sprite->getScale().y, 1);		
			sprite->getAnimator()->play(sprite->getNowAnimate_No(),deltaTime);
		}
	}   


	glPushMatrix;
	for (std::vector<Entity *>::iterator iterator = entityArray->begin(); iterator != entityArray->end(); iterator++) {
		Entity *entity = *iterator;
		if (entity->getSprite()->getAnimator() != NULL) {
			//glLoadIdentity();
			//glRotatef(sprite->getRotation(), 0.0f, 0.0f, 1.0f);
			//glScalef(sprite->getScale().x, sprite->getScale().y, 1);	
			glLoadIdentity();
			glTranslatef(entity->getSprite()->getPosition().x, entity->getSprite()->getPosition().y, 0);
			entity->getSprite()->getAnimator()->play(entity->getSprite()->getNowAnimate_No(), deltaTime);
		}
	}
	
	glPopMatrix;

	glfwSwapBuffers(_window);
	glfwPollEvents();
}


RenderSystem& RenderSystem::getRenderSystem()
{
	
	static RenderSystem *renderSystem = NULL;
	if (renderSystem == NULL) {
		renderSystem = new RenderSystem();
		//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glViewport(0, 0, 1000 * 16 / 9, 1000);

		glEnable(GL_TEXTURE_2D);

		glMatrixMode(GL_PROJECTION);
		glOrtho(0.0f, 1000 * 16 / 9, 0.0f, 1000, -1, 1);
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
