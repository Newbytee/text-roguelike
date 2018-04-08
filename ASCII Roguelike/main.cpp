#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <random>
#include <ctime>

#include "GameCore.h"
#include "Input.h"
#include "Enemy.h"

void initPlayer(Player &tmpPlayer);
std::vector<Enemy> initEnemies(GameCore core);

int main() {

	GameCore mainCore;
	Player player;
	Input input;

	std::vector<Enemy> enemyVector;
	bool gameIsRunning = true;

	initPlayer(player);

	std::cout << "\n\n\n\n";

	mainCore.prepareLevel(1);
	enemyVector = initEnemies(mainCore);
	std::cout << enemyVector[0].getEnemyY();
	mainCore.printLevel(player);
	mainCore.resetLevel();

	while (gameIsRunning) {

		switch (input.getKeypress()) {

		case 'a':
			if (player.getPlayerX() != 0) {

				player.movePlayer(-1, 0, mainCore.getLevelValue(player.getPlayerX() - 1, player.getPlayerY()));

			}
			break;
		case 'w':
			if (player.getPlayerY() != 0) {

				player.movePlayer(0, -1, mainCore.getLevelValue(player.getPlayerX(), player.getPlayerY() - 1));

			}
			break;
		case 's':
			if (player.getPlayerY() != mainCore.getLevelHeight() - 1) {

				player.movePlayer(0, 1, mainCore.getLevelValue(player.getPlayerX(), player.getPlayerY() + 1));

			}
			break;
		case 'd':
			if (player.getPlayerX() != mainCore.getLevelWidth(player.getPlayerY())) {

				player.movePlayer(1, 0, mainCore.getLevelValue(player.getPlayerX() + 1, player.getPlayerY()));

			}
			break;

		}

		mainCore.clearScreen();
		mainCore.printLevel(player);
		mainCore.resetLevel();
				
	}

	system("PAUSE");
	return 0;

}

void initPlayer(Player &tmpPlayer) {

	tmpPlayer.setPlayerX(2);
	tmpPlayer.setPlayerY(2);

}

std::vector<Enemy> initEnemies(GameCore core) {

	std::mt19937 randomGen(time(NULL));
	std::uniform_int_distribution<int> randomPosY(1, core.getLevelHeight());
	std::uniform_int_distribution<int> randomHp(core.getCurrentLevel(), core.getCurrentLevel() + 5);

	const static unsigned int enemyN = core.getCurrentLevel() + 1;
	bool validPos = false;

	std::vector<Enemy> enemies;
	enemies.reserve(enemyN);

	for (int i = 0; i < enemyN; i++) {

		int x = 0, y = 0, hp, maxHp;

		while (validPos == false) {

			y = randomPosY(randomGen);
			std::uniform_int_distribution<int> randomPosX(1, core.getLevelWidth(y));
			x = randomPosX(randomGen);

			//std::cout << x << '\t' << y << '\t' << core.getLevelValue(x, y) << '\t';

			switch (core.getLevelValue(x, y)) {

			case '.':
			case ',':
			case ' ':
				validPos = true;
				break;
			default:
				break;

			}

		}

		hp = randomHp(randomGen);
		std::uniform_int_distribution<int> randomMaxHp(hp, hp + 10);
		maxHp = randomMaxHp(randomGen);

		//std::cout << "\n\n" << x << "\t" << y;

		enemies.push_back(Enemy(x, y, hp, maxHp));

	}

	std::cout << enemies.size() << '\t' << enemies[0].getEnemyY() << '\n';

	return enemies;

}