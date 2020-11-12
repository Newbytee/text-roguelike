#include "Utils.h"
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

void initPlayer(Player &player, unsigned int x, unsigned int y, unsigned int attack, unsigned int hp, unsigned int maxHp);

int main() {
	Utils util;
	Level level;
	Player player;
	std::mt19937 randGen(time(NULL));
	std::vector<Enemy> enemies(9);
	std::uniform_int_distribution<int> randomHp(1, 6);	
	std::uniform_int_distribution<int> randomMove(-1, 1);
	char input;
	bool isRunning = true;
	bool hasWon = false;
	bool shouldBreak = false;
	bool shouldRun = true;
	level.setCurrentLevel(1);
	initPlayer(player, 2, 2, 3, 20, 40);
	level.initLevel(level.getCurrentLevel());
	std::uniform_int_distribution<unsigned int> randomXPlacement(1, level.getWidth() - 1);
	std::uniform_int_distribution<unsigned int> randomYPlacement(1, level.getHeight() - 1);
	for (unsigned int i = 0; i < enemies.size(); i++) {
		do {
			enemies[i].setX(randomXPlacement(randGen));
			enemies[i].setY(randomYPlacement(randGen));
		} while (level.getChar(enemies[i].getX(), enemies[i].getY()) != '.');
		enemies[i].setAttack(randomHp(randGen));
		unsigned int tmpHpValue = randomHp(randGen);
		enemies[i].setHp(tmpHpValue);
		enemies[i].setMaxHp(tmpHpValue * 2);
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

				for (unsigned int i = 0; i < enemies.size(); i++) {
					int x = randomMove(randGen);
					int y = randomMove(randGen);
					enemies[i].move(x, y);
					if (level.getChar(enemies[i].getX(), enemies[i].getY()) == '#') {
						x = x * -1;
						y = y * -1;
						enemies[i].move(x, y);
					}
					level.setChar(enemies[i].getX(), enemies[i].getY(), 'S');
				}	

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

				for (unsigned int i = 0; i < enemies.size(); i++) {
					if (level.getChar(enemies[i].getX(), enemies[i].getY() + 1) == '&' || level.getChar(enemies[i].getX(), enemies[i].getY() - 1) == '&' || level.getChar(enemies[i].getX(), enemies[i].getY() + 1) == '&' || level.getChar(enemies[i].getX() - 1, enemies[i].getY()) == '&' || level.getChar(enemies[i].getX() + 1, enemies[i].getY()) == '&' || level.getChar(enemies[i].getX() - 1, enemies[i].getY()) == '&') {
						enemies[i].modHealth(player.getAttack());
						player.modHealth(enemies[i].getAttack());
						std::cout << "Attack!\n";
					}
					if (player.getHp() <= 0) {
						hasWon = false;
						isRunning = false;
						shouldBreak = true;
					}
					if (enemies[i].getHp() <= 0) {
						enemies.erase(enemies.begin() + i);
						i--;
						std::cout << "The enemy was slain!\n";
					}
				}

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

#ifdef _WIN32
	system("PAUSE");
#elif linux
	system("read -rsp $'Press any key to continue...\n' -n 1 key");
#endif
	return 0;
}

void initPlayer(Player &player, unsigned int x, unsigned int y, unsigned int attack, unsigned int hp, unsigned int maxHp) {
	player.setX(x);
	player.setY(y);
	player.setAttack(attack);
	player.setHp(hp);
	player.setMaxHp(maxHp);
}
