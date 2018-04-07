#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "GameCore.h"
#include "Input.h"
#include "CoordManagement.h"

void initPlayer(Player &tmpPlayer);

int main() {

	GameCore core;
	Player player;
	Input input;
	CoordManagement coord;

	bool gameIsRunning = true;
	int levelWidth;
	int levelHeight;

	initPlayer(player);

	std::cout << "\n\n\n\n";

	core.prepareLevel(1);
	core.printLevel(player);
	core.resetLevel();

	levelHeight = core.getLevelHeight();
	coord.setLevelHeight(levelHeight);

	std::cout << "\n\n" << player.getPlayerX() << "\t" << player.getPlayerY() << "\n\n";

	while (gameIsRunning) {

		switch (input.getKeypress()) {

		case 'a':
			if (player.getPlayerX() != 0) {

				player.setPlayerX(player.getPlayerX() - 1);

			}
			break;
		case 'w':
			if (player.getPlayerY() != 0) {

				player.setPlayerY(player.getPlayerY() - 1);

			}
			break;
		case 's':
			if (player.getPlayerY() != core.getLevelHeight() - 1) {

				player.setPlayerY(player.getPlayerY() + 1);

			}
			break;
		case 'd':
			if (player.getPlayerX() != core.getLevelWidth(player.getPlayerY())) {

				player.setPlayerX(player.getPlayerX() + 1);

			}
			break;

		}

		core.clearScreen();

		if (coord.verifyCoords(player.getPlayerX(), player.getPlayerY())) {

			core.printLevel(player);

		}

		core.resetLevel();

		/*if (player.getPlayerY() >= 0 && player.getPlayerY() < levelHeight) {

			levelWidth = core.getLevelWidth(player.getPlayerY());

		}
				
		if (player.getPlayerX() < 0) {

			player.setPlayerX(0);

		} else if (player.getPlayerX() > levelWidth) {

			player.setPlayerX(levelWidth);

		}
		
		if (player.getPlayerY() < 0) {

			player.setPlayerY(0);

		} else if (player.getPlayerY() > levelHeight) {

			player.setPlayerY(levelHeight);

		}*/

		//core.clearScreen();
		//core.printLevel(player);
		//player.movePlayer(-1, 0);
		//core.resetLevel();
		
		std::cout << "\n\n" << player.getPlayerX() << "\t" << player.getPlayerY() << "\n\n";
				
	}

	system("PAUSE");
	return 0;

}

void initPlayer(Player &tmpPlayer) {

	tmpPlayer.setPlayerX(2);
	tmpPlayer.setPlayerY(2);

}