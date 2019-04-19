#include "GameMgr.h"

//print title screen
GameMgr::GameMgr(RenderWindow& window)
{
	resetGame();

	if (!font.loadFromFile("5x7.ttf"))
		cout << "couldn't load font";

	gameTitleText.setString("SPACE INVADERS");
	gameTitleText.setFont(font);
	gameTitleText.setCharacterSize(100);
	gameTitleText.setPosition((window.getSize().x / 2.0f) - (gameTitleText.getGlobalBounds().width / 2.0f), (window.getSize().y / 2.0f) - 200);

	buttonText.setString("PLAY");
	buttonText.setFont(font);
	buttonText.setCharacterSize(50);
	buttonText.setPosition((window.getSize().x / 2.0f) - (buttonText.getGlobalBounds().width / 2.0f), (window.getSize().y / 2.0f) - 40);

	startButton.setSize(Vector2f(150, 50));
	startButton.setOutlineThickness(2);
	startButton.setOutlineColor(Color::White);
	startButton.setPosition(Vector2f((window.getSize().x / 2.0f) - (startButton.getGlobalBounds().width / 2.0f), (window.getSize().y / 2.0f) - (startButton.getGlobalBounds().height / 2.0f)));

	livesText.setFont(font);
	livesText.setCharacterSize(40);

	levelText.setFont(font);
	levelText.setCharacterSize(40);

	scoreText.setFont(font);
	scoreText.setCharacterSize(40);

	gameoverText.setFont(font);
	gameoverText.setCharacterSize(100);
}
	
//resets the game values
void GameMgr::resetGame()
{
	isPlaying = false;
	levelFailed = false;
	won = false;
	lost = false;
	lives = 3;
	level = 1;
	score = 0;
}

bool GameMgr::getIsPlayingGame()
{
	return isPlaying;
}

void GameMgr::setIsPlaying(bool set)
{
	isPlaying = set;
}

//start game if you click play
void GameMgr::handleMouseUp(Vector2f pos)
{
	if (startButton.getGlobalBounds().contains(pos))
		isPlaying = true;
}

//draws default/start ui
void GameMgr::drawStartUI(RenderWindow& window)
{
	Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
	if (startButton.getGlobalBounds().contains(mouse)) 
	{
		startButton.setFillColor(Color::White);
		buttonText.setFillColor(Color::Black);
	}
	else 
	{
		startButton.setFillColor(Color::Transparent);
		buttonText.setFillColor(Color::White);
	}

	window.draw(gameTitleText);
	window.draw(startButton);
	window.draw(buttonText);
}

//draws the actual ui in game
void GameMgr::drawGameUI(RenderWindow& window)
{
	string str = "LIVES " + to_string(lives);
	livesText.setString(str);
	livesText.setPosition(((window.getSize().x / 4.0f) * 1.0f) - (livesText.getLocalBounds().width / 2.0f) - 50, -5);
	window.draw(livesText);

	str = "LEVEL " + to_string(level);
	levelText.setString(str);
	levelText.setPosition(((window.getSize().x / 4.0f) * 2.0f) - (levelText.getLocalBounds().width / 2.0f), -5);
	window.draw(levelText);

	str = "SCORE " + to_string(score);
	scoreText.setString(str);
	scoreText.setPosition(((window.getSize().x / 4.0f) * 3.0f) - (scoreText.getGlobalBounds().width / 2.0f) + 50, -5);
	window.draw(scoreText);
}

void GameMgr::drawGameoverUI(RenderWindow& window)
{
	lives = 0;
	if (won) 
		gameoverText.setString("YOU WIN!!!");
	else 
		gameoverText.setString("YOU LOSE!!");

	gameoverText.setPosition((window.getSize().x / 2.0f) - (gameoverText.getGlobalBounds().width / 2.0f), (window.getSize().y / 2.0f) - (gameoverText.getGlobalBounds().height / 2.0f));
	window.draw(gameoverText);
}

bool GameMgr::getLevelFailed()
{
	return levelFailed;
}

void GameMgr::setLevelCompleted(bool set)
{
	levelCompleted = set;
}

bool GameMgr::getLevelCompleted()
{
	return levelCompleted;
}

void GameMgr::setLevelFailed(bool set)
{
	levelFailed = set;
}

int GameMgr::getLevelHardness()
{
	return levelHardness[level - 1];
}

bool GameMgr::getWon()
{
	return won;
}

bool GameMgr::getLost()
{
	return lost;
}

void GameMgr::incrementScore()
{
	score++;
}

int GameMgr::getLevel()
{
	return level;
}

//if all enemies destroyed change difficulty
void GameMgr::nextLevel()
{
	if (level == 2)
		won = true;
	else
	{
		cout << "Next Level" << endl;
		level++;
		lives = 3;
		levelCompleted = false;
	}
}

void GameMgr::resetLevel()
{
	if (lives == 1)
	{
		lives = 0;
		lost = true;
	}
	else
	{
		cout << "Reset Level" << endl;
		lives--;
		levelFailed = false;
	}
}