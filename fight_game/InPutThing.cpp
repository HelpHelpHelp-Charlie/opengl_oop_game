#include "InPutThing.h"
#include"Player.h"

bool InPutThing::Input(bool trigger, Player * player, Tile * tile)
{
	if (this->enable) {
	if (trigger&&player->getGrabOrPlace() && !tile->getIsGrabingThing() && player->getIsGrabingThing()) {
		
			if (this->_onlyFor) {//�o�O�U����άO��L
				if (this->_onlyForType == int(this->_entityManager->getEntityArr()->
					at(_entityManager->getIDarray().at(player->getGrabEntityID()))->getType())) {//�P�_�⮳����O�_�ŦX�n�D
					player->setIsGrabingThing(false);
					this->_entityManager->removeEntity(player->getGrabEntityID());
					return true;
				}
				else {
					return false;
				}
			}
			else {
				player->setIsGrabingThing(false);
				this->_entityManager->removeEntity(player->getGrabEntityID());
				return true;
			}

	}
	}

	return false;
}
