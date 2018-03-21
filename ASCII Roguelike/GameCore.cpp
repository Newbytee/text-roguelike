#include "GameCore.h"
#include "Player.h"

#include <iostream>
#include <cstdlib>
#include <fstream>

GameCore::GameCore() {



}

void GameCore::clearScreen() {

	printf("%s", (std::string(100, '\n')).c_str());

}

void GameCore::prepareLevel(int levelN) {

	_currentLevel = levelN;

	std::ifstream levelFile("level" + std::to_string(levelN) + ".txt");

	if (!(levelFile.is_open())) {

		std::cout << perror;
		return;

	}

	std::string input;

	for (int i = 0; std::getline(levelFile, input); i++) {

		_level.push_back(input + "\0");

	}

}

void GameCore::printLevel(/*, Player player*/) {

	printf("hi");

}
