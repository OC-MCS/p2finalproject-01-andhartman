#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

//class for all the text as well as holding stats/conditions
class GameMgr {
private:
	bool isPlaying;
	bool lost;
	bool won;
	int lives;
	int level;
	int score;
	bool levelCompleted;
	bool levelFailed;
	int levelHardness[2] = { 1,2 };

	Font font;
	Text gameTitleText;
	Text buttonText;
	RectangleShape startButton;
	Text authorText;
	Text levelText;
	Text livesText;
	Text scoreText;
	Text gameoverText;
public:
	GameMgr(RenderWindow&);

	void resetGame();
	bool getIsPlayingGame();
	void setIsPlaying(bool);
	void handleMouseUp(Vector2f);
	void drawStartUI(RenderWindow&);
	void drawGameUI(RenderWindow&);
	void drawGameoverUI(RenderWindow&);
	bool getLevelFailed();
	void setLevelCompleted(bool);
	bool getLevelCompleted();
	void setLevelFailed(bool);
	int getLevelHardness();
	bool getWon();
	bool getLost();
	void incrementScore();
	int getLevel();
	void nextLevel();
	void resetLevel();
};