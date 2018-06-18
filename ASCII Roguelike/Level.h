#pragma once

#include <vector>

class Level {
public:
	Level();
	void setChar(unsigned int x, unsigned int y, char type);
	void setCurrentLevel(int level);
	void printLevel();
	void initLevel(int levelNumber);
	char getChar(unsigned int x, unsigned int y);
	int getCurrentLevel();
private:
	std::vector<std::string> _level;
	int _currentLevel;
};