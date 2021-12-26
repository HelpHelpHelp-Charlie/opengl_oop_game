#include "AbstractInteraction.h"
#include"Player.h"
bool AbstractInteraction::trigger(Vec2 thisLocation, Player * player)
{
	return (thisLocation.x / 150 == player->getAtGridTile().x + player->getEyeVector().x&&thisLocation.y / 150 == player->getAtGridTile().y + player->getEyeVector().y);

}
