#include "InPutThing.h"
#include"Player.h"

bool InPutThing::Input(bool trigger, Player * player, Tile * tile)
{
	if (this->enable) {
	if (trigger&&player->getGrabOrPlace() && !tile->getIsGrabingThing() && player->getIsGrabingThing()) {
		
			if (this->_onlyFor) {//這是垃圾桶或是其他
				if (this->_onlyForType == int(this->_entityManager->getEntityArr()->
					at(_entityManager->getIDarray().at(player->getGrabEntityID()))->getType())) {//判斷手拿物體是否符合要求
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
