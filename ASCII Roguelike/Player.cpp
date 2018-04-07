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

int Player::checkPos(std::vector<std::string> levelVector) {

	//std::vector<std::string>

	//switch()

	return 0;

}

void Player::movePlayer(int x, int y, char type) {

	GameCore core;

	int tmpX = (_playerX + x), tmpY (_playerY + y);

	switch (type) {

	case '#':
		break;
	default:
		_playerX += x;
		_playerY += y;
		break;

	}

}
