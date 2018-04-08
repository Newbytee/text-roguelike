#include "Enemy.h"

Enemy::Enemy() {



}

Enemy::Enemy(int x, int y, int health, int maxHealth) {

	_enemyX = x;
	_enemyY = y;
	_health = health;
	_maxHealth = maxHealth;

}

int Enemy::modEnemyHealth(int mod) {

	if (_health + mod > _maxHealth) {

		//remove excess heal

		int overflowTemp = (_health + mod) - _maxHealth;

		mod -= overflowTemp;

	} else if (_health + mod < _health) {

		//enemy dies

		if (_health < mod) {

			//brutal death, etc.

			return 2;

		}

		return 1;

	}

	_health += mod;

	return 0;

}