#include "grabFromBoxh.h"
#include"Player.h"
bool GrabFromBox::grab(bool trigger, Player * player, IngredientType type)
{
	if (this->enable) {
		if (trigger&&player->getGrabOrPlace() && !player->getIsGrabingThing()) {
			int h = this->_entityManager->addNewEntity(type);
			player->setGrabEntityID(h);
			player->setIsGrabingThing(true);
			return true;
		}
	}

	return false;
}
