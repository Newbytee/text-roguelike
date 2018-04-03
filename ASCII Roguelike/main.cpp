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

	core.prepareLevel(1);
	//core.printLevel(player);

	while (gameIsRunning) {

		switch (input.getKeypress()) {

		case 'a':
			player.setPlayerX(player.getPlayerX() - 1);
			break;
		case 'w':
			player.setPlayerY(player.getPlayerY() + 1);
			break;
		case 's':
			player.setPlayerY(player.getPlayerY() - 1);
			break;
		case 'd':
			player.setPlayerX(player.getPlayerX() + 1);
			break;

		}

		core.printLevel(player);

		std::cout << "\n\n" << player.getPlayerX() << "\t" << player.getPlayerY() << "\n\n";
				
	}

	system("PAUSE");
	return 0;

}

void initPlayer(Player &tmpPlayer) {

	tmpPlayer.setPlayerX(2);
	tmpPlayer.setPlayerY(2);

}