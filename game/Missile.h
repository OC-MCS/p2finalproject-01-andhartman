#pragma once
#include <iostream>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "enemy.h"

//class for one missile
class Missile
{
private:
	Sprite missile;
	Texture missileTexture;
	bool isFromShip;
public:
	Missile(Vector2f);

	void moveShipMissile();
	void moveAlienMissile(GameMgr& gameMgr);
	//void hit();
	Sprite& drawMissile();
	Vector2f getPos();
};