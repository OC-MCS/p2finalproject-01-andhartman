#pragma once
#include <iostream>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Ship.h"
#include "MissileMgr.h"
#include "EnemyMgr.h"
#include "GameMgr.h"

//collision class is made to check for collisions between the missiles and the enemies/ship
class Collision {
public:
	void checkEnemyCollisions(list<Enemy>&, list<Missile>&, GameMgr&);
	bool checkShipCollisions(Ship, list<Missile>&, GameMgr&);
};