#include "EnemyMgr.h"

//default constructor
EnemyMgr::EnemyMgr()
{
	srand(static_cast<unsigned int>(time(0)));
	enemies.clear();
	seconds=time(NULL);
}

//sets up the enemies, calls the function to add enemies - has loop to call multiple
void EnemyMgr::setupEnemies(GameMgr& gameMgr, int num)
{
	if (gameMgr.getLevelFailed())
		gameMgr.resetLevel();
	for (int i = 0; i < num; i++)
		addEnemy(Vector2f(80.0f * i + 20, 50.0f), gameMgr);
}

//adds an enemy
void EnemyMgr::addEnemy(Vector2f pos, GameMgr gamemgr)
{
	Enemy temp(pos, gamemgr);
	enemies.push_back(temp);
}


//moves all enemies and spawn enemy missiles - made it shoot with min interval of one second but it always shoots from the first enemy
void EnemyMgr::moveEnemies(GameMgr& gameMgr, MissileMgr& missileMgr, Ship ship)
{
	list<Enemy>::iterator iter2;
	iter2 = enemies.begin();
	for (iter = enemies.begin(); iter != enemies.end();)
	{
		if (iter->getPos().y < ship.getPosition().y && !gameMgr.getLevelFailed())
		{
			iter->moveEnemy(gameMgr);
			if (time(NULL)!=seconds)                                         //make sure it has been a second
			{
				seconds = time(NULL);
				if ((rand() % 2) < 1)
				{
					while (rand() % 5 != 2 && iter2 != enemies.end())     //my really weird way to choose a random enemy to shoot
					{
							iter2++;
					}
					if (iter2 == enemies.end())
						iter2 = enemies.begin();
					missileMgr.addAlienMissile(Vector2f((int)iter2->getPos().x + 5.0f, (int)iter2->getPos().y + 0.0f));
				}
			}
			iter++;
		}
		else
		{
			gameMgr.setLevelFailed(true);
			iter = enemies.erase(iter);
			break;
		}
	}
}

//draws all enemies
void EnemyMgr::drawEnemies(RenderWindow& window)
{
	for (iter = enemies.begin(); iter != enemies.end(); iter++)
	{
		window.draw(iter->draw());
	}
}


//returns enemies
list<Enemy>& EnemyMgr::getEnemies()
{
	return enemies;
}


//clears enemies
void EnemyMgr::clearEnemies()
{
	enemies.clear();
}