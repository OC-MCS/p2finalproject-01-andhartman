#pragma once
#include <iostream>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Missile.h"

//class that creates and stores all the missiles in lists
class MissileMgr {
private:
	list<Missile> shipMissiles;
	list<Missile> alienMissiles;
public:
	MissileMgr();

	void addShipMissile(Vector2f);
	void addAlienMissile(Vector2f);
	void moveMissiles(GameMgr& gameMgr);
	void drawMissiles(RenderWindow&);
	void clearMissiles();
	list<Missile>& getShipMissiles();
	list<Missile>& getAlienMissiles();
};