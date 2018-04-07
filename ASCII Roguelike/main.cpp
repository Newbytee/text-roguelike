#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "GameCore.h"
#include "Input.h"

void initPlayer(Player &tmpPlayer);

int main() {

	GameCore core;
	Player player;
	Input input;

	bool gameIsRunning = true;

	initPlayer(player);

	std::cout << "\n\n\n\n";

	core.prepareLevel(1);
	core.printLevel(player);
	core.resetLevel();

	std::cout << "\n\n" << player.getPlayerX() << "\t" << player.getPlayerY() << "\n\n";

	while (gameIsRunning) {

		switch (input.getKeypress()) {

		case 'a':
			if (player.getPlayerX() != 0) {

				player.movePlayer(-1, 0, core.getLevelValue(player.getPlayerX() - 1, player.getPlayerY()));

			}
			break;
		case 'w':
			if (player.getPlayerY() != 0) {

				player.movePlayer(0, -1, core.getLevelValue(player.getPlayerX(), player.getPlayerY() - 1));

			}
			break;
		case 's':
			if (player.getPlayerY() != core.getLevelHeight() - 1) {

				player.movePlayer(0, 1, core.getLevelValue(player.getPlayerX(), player.getPlayerY() + 1));

			}
			break;
		case 'd':
			if (player.getPlayerX() != core.getLevelWidth(player.getPlayerY())) {

				player.movePlayer(1, 0, core.getLevelValue(player.getPlayerX() + 1, player.getPlayerY()));

			}
			break;

		}

		core.clearScreen();
		core.printLevel(player);
		std::cout << core.getLevelValue(1, 1);
		core.resetLevel();
		
		std::cout << "\n\n" << player.getPlayerX() << "\t" << player.getPlayerY() << "\t" << core.getLevelValue(player.getPlayerX(), player.getPlayerY()) << "\n\n";
				
	}

	system("PAUSE");
	return 0;

}

void initPlayer(Player &tmpPlayer) {

	tmpPlayer.setPlayerX(2);
	tmpPlayer.setPlayerY(2);

}