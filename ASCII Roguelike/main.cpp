#include "Utils.h"
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

void initPlayer(Player &player, unsigned int x, unsigned int y, unsigned int hp, unsigned int maxHp);

int main() {
	Utils util;
	Level level;
	Player player;
	std::mt19937 randGen(time(NULL));
	std::vector<Enemy> enemies(3);
	std::uniform_int_distribution<int> randomHp(1, 6);	
	std::uniform_int_distribution<int> randomMove(0, 3);
	char input;
	bool isRunning = true;
	bool hasWon = false;
	bool shouldBreak = false;
	bool shouldRun = true;
	level.setCurrentLevel(1);
	initPlayer(player, 2, 2, 20, 40);
	level.initLevel(level.getCurrentLevel());
	std::uniform_int_distribution<unsigned int> randomXPlacement(1, level.getWidth() - 1);
	std::uniform_int_distribution<unsigned int> randomYPlacement(1, level.getHeight() - 1);
	for (unsigned int i = 0; i < enemies.size(); i++) {
		do {
			enemies[i].setX(randomXPlacement(randGen));
			enemies[i].setY(randomYPlacement(randGen));
		} while (level.getChar(enemies[i].getX(), enemies[i].getY()) == '#');
		enemies[i].setAttack(randomHp(randGen));
		unsigned int tmpHpValue = randomHp(randGen);
	}	
	for (unsigned int i = 0; i < enemies.size(); i++) {
		level.setChar(enemies[i].getX(), enemies[i].getY(), 'S');
	}
	level.setChar(player.getX(), player.getY(), '&');
	util.clearScreen();
	level.printLevel();

	while (isRunning) {
		input = util.getKeyPress();
		switch (input) {
		case 'a':
		case 'w':
		case 's':
		case 'd':
			if (shouldRun) {
				level.initLevel(level.getCurrentLevel());

				for (int i = 0; i < enemies.size(); i++) {
					level.setChar(enemies[i].getX(), enemies[i].getY(), 'S');
				}

				//enemies[1].testMethod();				

				switch (input) {
				case 'a':
					switch (level.getChar(player.getX() - 1, player.getY())) {
					case '#':
						break;
					default:
						player.move(-1, 0);
						break;
					}
					break;
				case 'w':
					switch (level.getChar(player.getX(), player.getY() - 1)) {
					case '#':
						break;
					default:
						player.move(0, -1);
						break;
					}
					break;
				case 's':
					switch (level.getChar(player.getX(), player.getY() + 1)) {
					case '#':
						break;
					default:
						player.move(0, 1);
						break;
					}
					break;
				case 'd':
					switch (level.getChar(player.getX() + 1, player.getY())) {
					case '#':
						break;
					default:
						player.move(1, 0);
						break;
					}
					break;
				}

				switch (level.getChar(player.getX(), player.getY())) {
				case 'E':
					hasWon = true;
					isRunning = false;
					shouldBreak = true;
					break;
				case 'O':
					hasWon = false;
					isRunning = false;
					shouldBreak = true;
					break;
				case 'S':
					break;
				default:
					break;
				}

				if (shouldBreak) {
					break;
				}

				level.setChar(player.getX(), player.getY(), '&');
				util.clearScreen();
				level.printLevel();
			}
			break;
		}
	}

	util.clearScreen();
	level.printLevel();
	if (hasWon) {
		std::cout << "You win!\n";
	} else {
		std::cout << "You lose!\n";
	}

	system("PAUSE");
	return 0;
}

void initPlayer(Player &player, unsigned int x, unsigned int y, unsigned int hp, unsigned int maxHp) {
	player.setX(x);
	player.setY(y);
	player.setHp(hp);
	player.setMaxHp(maxHp);
}