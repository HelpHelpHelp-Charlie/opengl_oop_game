#include "PlaceThing.h"
#include"Player.h"
bool PlaceThing::Place(bool trigger, Player * player,Tile* tile)
{


	if (trigger&&player->getGrabOrPlace() && !tile->getIsGrabingThing()) {
		tile->setGrabEntityID(player->getGrabEntityID());
		tile->setIsGrabingThing(true);
		player->setIsGrabingThing(false);
	}
	return false;
}
