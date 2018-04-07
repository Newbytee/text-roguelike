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

	char getLevelValue(int x, int y) { return _level[y][x]; };

	//setters

	void setCurrentLevel(int level) { _currentLevel = level; };

private:

	int _currentLevel;
	std::vector<std::string> _level;

};