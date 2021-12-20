//
//  MovementSystem.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 18/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "MovementSystem.h"

MovementSystem::MovementSystem()
{

}

MovementSystem::~MovementSystem()
{

}

void MovementSystem::update(std::vector<Player *> *playerArray)
{
	for (std::vector<Player *>::iterator iterator = playerArray->begin(); iterator != playerArray->end(); iterator++) {

		Player *player = *iterator;
		player->update();
	//	player->setPosition(player->getPosition()+ player->getVelocity());
	//	entity->setScale(entity->getScale() + entity->getScaleVelocity());
		//entity->setRotation(entity->getRotation() + entity->getRotationVelocity());

	}
}

MovementSystem& MovementSystem::getMovementSystem()
{
	static MovementSystem* movementSystem = NULL;

	if (movementSystem == NULL) {
		movementSystem = new MovementSystem();
	}

	return *movementSystem;
}

void MovementSystem::destroyMovementSystem()
{
	MovementSystem *movementSystem = &getMovementSystem();
	delete movementSystem;
}