#include "Player.h"

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
