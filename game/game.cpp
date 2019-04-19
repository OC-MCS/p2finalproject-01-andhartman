//============================================================
// Andrew Hartman
// April 19, 2019
// Final Project
// Description: Space Invaders
//============================================================

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 
#include "Collision.h"
#include "EnemyMgr.h"
#include "GameMgr.h"
#include "MissileMgr.h"
#include "Ship.h"

int main()
{
	int resetTime = 0;
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	window.setFramerateLimit(60);

	//load and set background texture
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Sprite background;
	background.setTexture(starsTexture);
	background.setScale(1.5, 1.5);

	GameMgr gameMgr(window);
	Ship ship(Vector2f(375, 550));
	MissileMgr missileMgr;
	EnemyMgr enemyMgr;
	Collision collision;

	//put in enemies
	enemyMgr.setupEnemies(gameMgr, 10);

	while (window.isOpen())
	{
		Event event;
		window.draw(background);

		if (gameMgr.getIsPlayingGame() && !gameMgr.getLost() && !gameMgr.getWon())                                   //make sure game is being played and they havent won or lost
		{
			gameMgr.drawGameUI(window);

			if (enemyMgr.getEnemies().empty() && (gameMgr.getLevelFailed() || gameMgr.getLevelCompleted()))          //if all the enemies are gone
			{
				enemyMgr.setupEnemies(gameMgr, 10);
				resetTime = static_cast<int>(time(NULL)) + 2;
				missileMgr.clearMissiles();
			}
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				else if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Space)                                                              //shoot when space is pressed
					{
						missileMgr.addShipMissile(Vector2f(ship.getPosition().x + 7, ship.getPosition().y + 6));
					}
				}
			}
			ship.move();
			window.draw(ship.draw());
			enemyMgr.drawEnemies(window);

			if (resetTime <= time(0))
			{
				enemyMgr.moveEnemies(gameMgr, missileMgr, ship);
				missileMgr.moveMissiles(gameMgr);
			}

			enemyMgr.drawEnemies(window);
			missileMgr.drawMissiles(window);

			collision.checkEnemyCollisions(enemyMgr.getEnemies(), missileMgr.getShipMissiles(), gameMgr);       //check for missile enemy collision
			if (collision.checkShipCollisions(ship, missileMgr.getAlienMissiles(), gameMgr))                    //check for bomb hitting ship
			{
				gameMgr.setLevelFailed(true);
				enemyMgr.clearEnemies();
			}
		}
		else if (gameMgr.getLost() || gameMgr.getWon())                                                                 //if won or lost
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			gameMgr.drawGameUI(window);
			gameMgr.drawGameoverUI(window);
		}
		else
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				else if (event.type == Event::MouseButtonReleased)
				{
					Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
					gameMgr.handleMouseUp(mouse);
				}
			}
			gameMgr.drawStartUI(window);
		}
		window.display();
	}

	return 0;
}

