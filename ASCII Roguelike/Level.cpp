#include "Level.h"
#include <fstream>
#include <string>
#include <iostream>

Level::Level() {
}

void Level::setChar(unsigned int x, unsigned int y, char type) {
	_level[y][x] = type;
}

void Level::setCurrentLevel(int level) {
	_currentLevel = level;
}

void Level::printLevel() {
	int levelYSize = _level.size();

	for (int x = 0; x < levelYSize; x++) {
		for (unsigned int y = 0; y < _level[x].length(); y++) {
			printf("%c%c", _level[x][y], ' ');
		}
		printf("\n");
	}
}

void Level::initLevel(int levelNumber) {
	std::ifstream levelFile("level" + std::to_string(levelNumber) + ".txt");

	if (!(levelFile.is_open())) {
		std::cout << perror;
		return;
	}

	std::string input;

	for (int i = 0; std::getline(levelFile, input); i++) {
		_level.push_back(input + '\0');
	}
}

char Level::getChar(unsigned int x, unsigned int y) {
	return _level[y][x];
}

int Level::getCurrentLevel() {
	return _currentLevel;
}