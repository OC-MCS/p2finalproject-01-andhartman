#include "Missile.h"

//constructor 
Missile::Missile(Vector2f pos)
{
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}

	missile.setTexture(missileTexture);
	missile.setPosition(pos);
}

//moves missile up
void Missile::moveShipMissile()
{
	missile.setTexture(missileTexture);
	missile.move(0, -10);
}

//move bomb down
void Missile::moveAlienMissile(GameMgr& gameMgr)
{
	missile.setTexture(missileTexture);
	if (gameMgr.getLevelHardness() == 1)
		missile.move(0, 2);
	else
		missile.move(0, 4);
}

Sprite& Missile::drawMissile()
{
	return missile;
}

Vector2f Missile::getPos()
{
	return missile.getPosition();
}