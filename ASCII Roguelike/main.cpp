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
	core.printLevel(player);

	while (gameIsRunning) {

		switch (input.getKeypress()) {



		}

		

	}

	system("PAUSE");
	return 0;

}

void initPlayer(Player &tmpPlayer) {

	tmpPlayer.setPlayerX(2);
	tmpPlayer.setPlayerY(2);

}