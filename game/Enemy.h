#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "GameMgr.h"

//class for handling one enemy
class Enemy {
private:
	Sprite enemy;
	Texture enemyTexture;
public:
	Enemy(Vector2f pos, GameMgr& gamemgr);

	Sprite& draw();
	void moveEnemy(GameMgr&);
	Vector2f getPos();
};