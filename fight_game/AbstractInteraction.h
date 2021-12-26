#pragma once
#ifndef  __FightGame__AbstractInteraction__
#define __FightGame__AbstractInteraction__
#include"Vec2.h"
#include"EntityManager.h"

class Player;

class AbstractInteraction {
private:
protected:	
	bool enable;

public:
	Vec2 _thisLocation;
//	bool trigger(Vec2 thisLocation,Vec2 playerLocation,Vec2 playerLookAt) {
	bool trigger(Vec2 thisLocation, Player* player); //{
	void setEnable(bool e) {this->enable=e;}
	bool getEnable() { return this->enable; }
		//return (thisLocation.x/100== playerLocation.x+ playerLookAt.x&&thisLocation.y / 100 == playerLocation.y + playerLookAt.y);
	//}
};
#endif