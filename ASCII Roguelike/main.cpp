#include "Utils.h"
#include "Level.h"
#include "Player.h"
#include <iostream>

void initPlayer(Player &player);

int main() {
	Utils util;
	Level level;
	Player player;
	bool isRunning = true;
	bool hasWon = false;
	bool shouldBreak = false;
	level.setCurrentLevel(1);
	initPlayer(player);
	level.initLevel(level.getCurrentLevel());
	level.setChar(player.getX(), player.getY(), '&');
	util.clearScreen();
	level.printLevel();

	while (isRunning) {		
		level.initLevel(level.getCurrentLevel());

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
		default:
			break;
		}

		if (shouldBreak) {
			break;
		}

		switch (util.getKeyPress()) {
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

		level.setChar(player.getX(), player.getY(), '&');
		util.clearScreen();
		level.printLevel();
	}

	util.clearScreen();
	if (hasWon) {		
		std::cout << "You win!\n";
	} else {
		std::cout << "You lose!\n";
	}

	system("PAUSE");
	return 0;
}

void initPlayer(Player &player) {
	player.setX(1);
	player.setY(1);
}