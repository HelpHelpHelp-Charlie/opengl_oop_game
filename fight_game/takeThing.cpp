#include "takeThing.h"
#include"Player.h"

bool TakeThing::Take(bool trigger, Player * player, Tile * tile,bool call)
{
	if(call){
		
		if (this->enable&&trigger&&!player->getGrabOrPlace() && tile->getIsGrabingThing() && !player->getIsGrabingThing()) {
			player->setGrabEntityID(tile->getGrabEntityID());
			player->setIsGrabingThing(true);cout << "ff"<<endl;
			tile->setIsGrabingThing(false);
			this->enable = false;
			return true;
		}
		else {
			if (trigger&&player->getGrabOrPlace() && tile->getIsGrabingThing() && !player->getIsGrabingThing()) {
				this->enable = true;
				return false;
			}
			return false;
		}
	}
	return false;
}

