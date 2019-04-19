#include "Collision.h"

//check for collisions between the enemies and missiles
void Collision::checkEnemyCollisions(list<Enemy>& enemies, list<Missile>& missiles, GameMgr& gameMgr)
{
	list<Enemy>::iterator eIter;
	list<Missile>::iterator mIter;
	for (eIter = enemies.begin(); eIter != enemies.end(); eIter++)
	{
		for (mIter = missiles.begin(); mIter != missiles.end(); mIter++)
		{
			if (eIter->draw().getGlobalBounds().contains(mIter->getPos()))
			{
				eIter = enemies.erase(eIter);
				mIter = missiles.erase(mIter);
				gameMgr.incrementScore();
				if (enemies.empty())
				{
					gameMgr.nextLevel();
					gameMgr.setLevelCompleted(true);
				}
				return;
			}
		}
	}
}

//check for collisions between the ship and missiles
bool Collision::checkShipCollisions(Ship ship, list<Missile>& missiles, GameMgr& gameMgr)
{
	list<Missile>::iterator iter;
	for (iter = missiles.begin(); iter != missiles.end(); iter++)
	{
		if (ship.draw().getGlobalBounds().contains(iter->getPos()))
		{
			iter = missiles.erase(iter);
			return true;
		}
	}
	return false;
}