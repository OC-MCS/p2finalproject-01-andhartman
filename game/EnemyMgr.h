#pragma once
#include <iostream>
#include <list>
#include <ctime>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Enemy.h"
#include "GameMgr.h"
#include "MissileMgr.h"
#include "Ship.h"

//creates a list of enemies so there can be multiple enemies
class EnemyMgr {
private:
	list<Enemy> enemies;
	list<Enemy>::iterator iter;
	time_t seconds;
public:
	EnemyMgr();

	void setupEnemies(GameMgr&, int);
	void addEnemy(Vector2f pos, GameMgr gamemgr);
	void moveEnemies(GameMgr&, MissileMgr&, Ship);
	void drawEnemies(RenderWindow&);
	list<Enemy>& getEnemies();
	void clearEnemies();
};