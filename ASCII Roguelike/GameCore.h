#pragma once

#include <string>
#include <vector>

#include "Player.h"

class GameCore {

public:

	GameCore();

	void clearScreen();
	void prepareLevel(int levelN);
	void resetLevel();
	void printLevel(Player player);

	//getters

	int getCurrentLevel() { return _currentLevel; };
	int getLevelWidth(int y) { return _level[y].size() - 1; };
	int getLevelHeight() { return _level.size(); };
	int getStaticLevelHeight() { return _levelHeight; };

	char getLevelValue(int x, int y) { return _level[y][x]; };

	//setters

	void setCurrentLevel(int level) { _currentLevel = level; };

private:

	void setStaticHeight(int tmpStaticHeight) { _levelHeight = tmpStaticHeight; };
	int _currentLevel;
	unsigned int _levelHeight;
	std::vector<std::string> _level;

};