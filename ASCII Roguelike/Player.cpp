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

bool Player::movePlayer(int x, int y) {

	GameCore core;

	x += _playerX;
	y += _playerY;

	std::cout << x << "\t" << y;

	char moveSpot = core.getLevelValue(x, y);

	//std::cout << moveSpot;

	//switch(core.)

	return false;

}
