#include "PlayerInputSystem.h"

void PlayerInputSystem::setCurrentPlayer(Player *newPlayer)
{
	_currentPlayer = newPlayer;
	_eyeVector = newPlayer->getEyeVector();
}

PlayerInputSystem::PlayerInputSystem() : _window(glfwGetCurrentContext())
{
	
	glfwGetCursorPos(_window, &_lastMousePosition.x, &_lastMousePosition.y);
}

PlayerInputSystem::~PlayerInputSystem()
{

}

void PlayerInputSystem::keyCallback(GLFWwindow *window,
	int key,
	int scancode,
	int action,
	int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {

		if (GLFW_CURSOR_DISABLED == glfwGetInputMode(glfwGetCurrentContext(), GLFW_CURSOR)) {
			glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
		else {
			glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}

	}

}

void PlayerInputSystem::update()
{
	if (_currentPlayer != NULL //&&
		//glfwGetInputMode(_window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED
		) {

		if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
			_currentPlayer->setVelocity(Vec2(_currentPlayer->getVelocity().x, 3));
			_currentPlayer->setNowAnimate_No(0);
			_currentPlayer->setEyeVector(Vec2(0, 1));
		}
			

		if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
			_currentPlayer->setVelocity(Vec2(_currentPlayer->getVelocity().x, -3));
			_currentPlayer->setNowAnimate_No(2);
			_currentPlayer->setEyeVector(Vec2(0,-1 ));
		}

		if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_RELEASE&&glfwGetKey(_window, GLFW_KEY_W) == GLFW_RELEASE) {
			_currentPlayer->setVelocity(Vec2(_currentPlayer->getVelocity().x, 0));
		}


		if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
			_currentPlayer->setVelocity(Vec2(-3, _currentPlayer->getVelocity().y));
			_currentPlayer->setNowAnimate_No(4);
			_currentPlayer->setEyeVector(Vec2(-1, 0));
		}

		if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
			_currentPlayer->setVelocity(Vec2(3, _currentPlayer->getVelocity().y));
			_currentPlayer->setNowAnimate_No(6);
			_currentPlayer->setEyeVector(Vec2(1, 0));
		}

		if (glfwGetKey(_window, GLFW_KEY_P) == GLFW_PRESS) {

		}



		if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_RELEASE&&glfwGetKey(_window, GLFW_KEY_A) == GLFW_RELEASE) {
			_currentPlayer->setVelocity(Vec2(0, _currentPlayer->getVelocity().y));			
		}

		if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_RELEASE&&glfwGetKey(_window, GLFW_KEY_A) == GLFW_RELEASE&&
			glfwGetKey(_window, GLFW_KEY_S) == GLFW_RELEASE&&glfwGetKey(_window, GLFW_KEY_W) == GLFW_RELEASE) {
			if (_currentPlayer->getEyeVector().x==0&& _currentPlayer->getEyeVector().y == 1) {
				_currentPlayer->setNowAnimate_No(1);
			}else if (_currentPlayer->getEyeVector().x == 0 && _currentPlayer->getEyeVector().y == -1) {
				_currentPlayer->setNowAnimate_No(3);
			}else if(_currentPlayer->getEyeVector().x ==-1 && _currentPlayer->getEyeVector().y == 0 ) {
				_currentPlayer->setNowAnimate_No(5);
			}else {
				_currentPlayer->setNowAnimate_No(7);
			}

		}

		//Vector2 currentMousePosition;
	//	glfwGetCursorPos(_window, &currentMousePosition.x, &currentMousePosition.y);

	//	_eyeVector = transformVector3(_eyeVector, makeRotationMatrix3((3.14f / (4.0f*45.0f))*-(currentMousePosition.x - _lastMousePosition.x), 0.0f, 1.0f, 0.0f));

	//	glfwGetCursorPos(_window, &_lastMousePosition.x, &_	lastMousePosition.y);

	//	_currentPlayer->setEyeVector(addVector3(_currentPlayer->getPosition(), _eyeVector));

	}
}

void PlayerInputSystem::keyCallbackFun(GLFWwindow *window,
	int key,
	int scancode,
	int action,
	int mods)
{
	PlayerInputSystem *playerInputSystem = &getPlayerInputSystem();
	playerInputSystem->keyCallback(window, key, scancode, action, mods);
}

PlayerInputSystem& PlayerInputSystem::getPlayerInputSystem()
{
	static PlayerInputSystem *playerInputSystem = NULL;

	if (playerInputSystem == NULL) {


		glfwSetKeyCallback(glfwGetCurrentContext(), *keyCallbackFun);
		//	glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		playerInputSystem = new PlayerInputSystem();
	}

	return *playerInputSystem;
}

void PlayerInputSystem::destroyPlayerInputSystem()
{
	PlayerInputSystem *playerInputSystem = &getPlayerInputSystem();
	delete playerInputSystem;
}
