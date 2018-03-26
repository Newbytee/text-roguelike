#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "GameCore.h"

void initPlayer(Player &tmpPlayer);

int main() {

	GameCore core;
	Player player;

	initPlayer(player);

	core.prepareLevel(1);
	core.printLevel(player);

	system("PAUSE");
	return 0;

}

void initPlayer(Player &tmpPlayer) {

	tmpPlayer.setPlayerX(3);
	tmpPlayer.setPlayerY(3);

}