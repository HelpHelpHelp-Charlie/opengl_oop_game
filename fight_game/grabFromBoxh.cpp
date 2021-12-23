#include "grabFromBoxh.h"
#include"Player.h"
bool GrabFromBox::grab(bool trigger, Player * player, IngredientType type)
{
	if (trigger&&player->getGrab() && !player->getIsGrabingThing()) {
		int h = this->_entityManager->addNewEntity(type);
		cout << h;
		player->setGrabEntityID(h);
		player->setIsGrabingThing(true);
		return true;
	}
	return false;
}
