#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

//class for the ship
class Ship {
private:
	Sprite ship;
	Texture shipTexture;
	const float DISTANCE = 5.0;
public:
	Ship(Vector2f);

	void move();
	Vector2f getPosition();
	void setPosition(Vector2f);
	Sprite& draw();
};