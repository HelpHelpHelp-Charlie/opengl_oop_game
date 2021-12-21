#include "GameManager.h"

GameManager::GameManager(bool running) :_running(running),
_window(glfwGetCurrentContext()),
_renderSystem(&RenderSystem::getRenderSystem()),
_resourceManager(&ResourceManager::getResourceManager()),
_movementSystem(&MovementSystem::getMovementSystem()),
_playerInputSystem(&PlayerInputSystem::getPlayerInputSystem()),
scene(new Scene) {
}

GameManager::~GameManager()
{
	RenderSystem::destroyRenderSystem();
}

void GameManager::runGameLoop()
{
	double lastTime = glfwGetTime();
	double deltaTime = 0.0f;
	_playerInputSystem->setCurrentPlayer(scene->getChildrenPlayer()->at(0));
	while (_running)
	{

		_renderSystem->render(scene->getGridMap(), scene->getChildrenEntity(), deltaTime);
		deltaTime += (glfwGetTime() - lastTime)*Update_per_second;
		lastTime = glfwGetTime();

		while (deltaTime >= 1.0f) {
			_running = !glfwWindowShouldClose(_window);


			_playerInputSystem->update();
			_movementSystem->update(scene->getChildrenPlayer());
			scene->getGridMap()->update(scene->getChildrenPlayer()->at(0)->getAtGridTile(), scene->getChildrenPlayer()->at(0)->getEyeVector());
			--deltaTime;
		}
	}
}

GameManager &GameManager::getGameManager()
{
	static GameManager *gameManager = NULL;
	if (gameManager == NULL) {
		glfwInit();
		glfwWindowHint(GLFW_DEPTH_BITS, 24);
		glfwWindowHint(GLFW_RED_BITS, 8);
		glfwWindowHint(GLFW_GREEN_BITS, 8);
		glfwWindowHint(GLFW_BLUE_BITS, 8);
		glfwWindowHint(GLFW_ALPHA_BITS, 8);
		GLFWwindow *window = glfwCreateWindow(1280, 720, "OverCooked", NULL, NULL);
		glfwSwapInterval(0);
		glfwMakeContextCurrent(window);

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);//initialize glad
		gameManager = new GameManager(true);
		std::cout << "gameManager is created" << std::endl;
	}
	return *gameManager;
}

void GameManager::destroyGameManager() {
	GameManager *gameManager = &GameManager::getGameManager();
	delete gameManager;
	std::cout << "gameManager is destroyed" << std::endl;
	GLFWwindow *window = glfwGetCurrentContext();
	glfwDestroyWindow(window);
	glfwTerminate();
}