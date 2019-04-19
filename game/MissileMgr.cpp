#include "MissileMgr.h"

//default constructor
MissileMgr::MissileMgr()
{
	shipMissiles.clear();
	alienMissiles.clear();
}

//adds friendly missile
void MissileMgr::addShipMissile(Vector2f pos)
{
	Missile temp(pos);
	shipMissiles.push_back(temp);
}

//adds enemy missile
void MissileMgr::addAlienMissile(Vector2f pos)
{
	Missile temp(pos);
	alienMissiles.push_back(temp);
}

//moves all on screen missiles
void MissileMgr::moveMissiles(GameMgr& gameMgr)
{
	list<Missile>::iterator iter;
	for (iter = shipMissiles.begin(); iter != shipMissiles.end();) 
	{
		if (iter->getPos().y > 40) 
		{
			iter->moveShipMissile();
			iter++;
		}
		else
			iter = shipMissiles.erase(iter);
	}
	for (iter = alienMissiles.begin(); iter != alienMissiles.end();) 
	{
		if (iter->getPos().y < 570) 
		{
			iter->moveAlienMissile(gameMgr);
			iter++;
		}
		else
			iter = alienMissiles.erase(iter);
	}
}

//draw missiles
void MissileMgr::drawMissiles(RenderWindow& window)
{
	list<Missile>::iterator iter;
	for (iter = shipMissiles.begin(); iter != shipMissiles.end(); iter++)
		window.draw(iter->drawMissile());

	for (iter = alienMissiles.begin(); iter != alienMissiles.end(); iter++)
		window.draw(iter->drawMissile());
}

void MissileMgr::clearMissiles()
{
	shipMissiles.clear();
	alienMissiles.clear();
}

list<Missile>& MissileMgr::getShipMissiles()
{
	return shipMissiles;
}

list<Missile>& MissileMgr::getAlienMissiles()
{
	return alienMissiles;
}