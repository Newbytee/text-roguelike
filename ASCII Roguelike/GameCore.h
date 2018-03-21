#pragma once

#include <string>
#include <vector>

class GameCore {

public:

	GameCore();

	void clearScreen();
	void prepareLevel(int levelN);
	void printLevel(/*, Player player*/);

	//setters

	void setCurrentLevel(int level) { _currentLevel = level; };

private:

	int _currentLevel;
	std::vector<std::string> _level;

};