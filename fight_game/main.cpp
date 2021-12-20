#include"GameManager.h"
#include<glad\glad.h>
#include<iostream>
int main(int argc, char* argv[]) {
	GameManager *gameManager = &GameManager::getGameManager();
	gameManager->runGameLoop();
	GameManager::destroyGameManager();
	
	system("PAUSE");
	return 0;
}

