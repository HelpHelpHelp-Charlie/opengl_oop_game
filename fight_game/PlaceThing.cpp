#include "PlaceThing.h"
#include"Player.h"
bool PlaceThing::Place(bool trigger, Player * player, Tile* tile, bool call)
{
	if(call){
		if (this->enable&&trigger&&!player->getGrabOrPlace() && !tile->getIsGrabingThing() && player->getIsGrabingThing()) {
			tile->setGrabEntityID(player->getGrabEntityID());
			tile->setIsGrabingThing(true);
			player->setIsGrabingThing(false);
			this->enable = false;
			return true;
		}
		else {
			if (trigger&&player->getGrabOrPlace() && !tile->getIsGrabingThing() && player->getIsGrabingThing()) {
				this->enable = true;
				return false;
			}
			return false;
		}
	}
	return false;
}
