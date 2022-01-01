#include "Combine.h"
#include"Player.h"
bool Combine::CombineOnTile(bool trigger, Player * player, Tile * tile)
{


	if (trigger&&player->getGrabOrPlace() && tile->getIsGrabingThing() && player->getIsGrabingThing()) {

		IngredientType temp = this->_machingSystem->matching(IngredientType(this->_entityManager->getEntityArr()->at(this->_entityManager->getIDarray().at(tile->getGrabEntityID()))->getType()),
			IngredientType(this->_entityManager->getEntityArr()->at(this->_entityManager->getIDarray().at(player->getGrabEntityID()))->getType()));

		if (IngredientType::NumberOfIngredientItem != temp) {
			player->setIsGrabingThing(false);
			this->_entityManager->removeEntity(player->getGrabEntityID());
			this->_entityManager->removeEntity(tile->getGrabEntityID());
			tile->setGrabEntityID(this->_entityManager->addNewEntity(temp));

		}

		return false;
	}
}
