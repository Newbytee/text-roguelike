#include "Player.h"
#include "GameCore.h"

#include <iostream>

Player::Player() {



}

int Player::modPlayerHealth(int mod) {

	if (_health + mod > _maxHealth) {

		//remove excess heal

		int overflowTemp = (_health + mod) - _maxHealth;

		mod -= overflowTemp;

	} else if (_health + mod < _health) {

		//player dies

		if (_health < mod) {

			//brutal death, etc.

			return 2;

		}

		return 1;

	}

	_health += mod;

	return 0;

}

bool Player::movePlayer(int x, int y, char type) {

	GameCore core;

	std::cout << type;

	int tmpX = (_playerX + x), tmpY (_playerY + y);

	//std::cout << tmpX << "\t" << tmpY;

	//std::cout << core.getLevelValue(1, 1);

	//system("PAUSE");

	switch (type) {

	case '.':
	case ',':
		_playerX += x;
		_playerY += y;
		break;
	default:
		std::cout << "Unable to move!";
		break;

	}

	//system("PAUSE");

	//std::cout << x << "\t" << y;

	return false;

}
