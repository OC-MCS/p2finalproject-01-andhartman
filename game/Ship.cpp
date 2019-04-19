#include "Ship.h"

//constructor
Ship::Ship(Vector2f pos)
{
	if (!shipTexture.loadFromFile("ship.png")) 
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	
	ship.setTexture(shipTexture);
	ship.setPosition(pos.x, pos.y);
}

//moves the ship when buttons are pressed
void Ship::move()
{
	Vector2f pos = ship.getPosition();
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (pos.x >= 5)
			ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (pos.x <= 775)
			ship.move(DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (pos.y >= 600*.8)
			ship.move(0, -DISTANCE);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		if (pos.y <= 575)
			ship.move(0, DISTANCE);
	}
}

Vector2f Ship::getPosition()
{
	return ship.getPosition();
}

void Ship::setPosition(Vector2f pos)
{
	ship.setPosition(pos.x, pos.y);
}

Sprite& Ship::draw()
{
	return ship;
}