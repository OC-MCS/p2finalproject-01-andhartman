#include "Enemy.h"

//constructor - creates enemy at a position pos
Enemy::Enemy(Vector2f pos, GameMgr& gamemgr)
{
	if (gamemgr.getLevelHardness() == 1)
	{
		if (!enemyTexture.loadFromFile("enemy.png"))
		{
			cout << "Unable to load enemy texture!" << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!enemyTexture.loadFromFile("enemy2.png"))
		{
			cout << "Unable to load enemy texture!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	enemy.setTexture(enemyTexture);
	enemy.setPosition(pos.x, pos.y);
}

//moves the enemy down
void Enemy::moveEnemy(GameMgr& gameMgr)
{
	if (gameMgr.getLevelHardness() == 1)
		enemy.move(0, 0.5);
	else
		enemy.move(0, 1);
}

//return enemy position
Vector2f Enemy::getPos()
{
	return enemy.getPosition();
}

//draws an enemy
Sprite& Enemy::draw()
{
	return enemy;
}