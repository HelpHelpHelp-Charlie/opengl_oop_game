#include "AbstractInteraction.h"
#include"Player.h"
bool AbstractInteraction::trigger(Vec2 thisLocation, Player * player)
{
	return (thisLocation.x / 100 == player->getAtGridTile().x + player->getEyeVector().x&&thisLocation.y / 100 == player->getAtGridTile().y + player->getEyeVector().y);

}
