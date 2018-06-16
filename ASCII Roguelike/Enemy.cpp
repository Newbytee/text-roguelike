#include "Enemy.h"

Enemy::Enemy() {
}

Enemy::Enemy(int x, int y, int hp, int maxHp) {
	_x = x;
	_y = y;
	_hp = hp;
	_maxHp = maxHp;
}

int Enemy::modHealth(int mod) {
	if (mod )
	return 0;
}

void Enemy::setX(int x) {
	_x = x;
}

void Enemy::setY(int y) {
	_y = y;
}

int Enemy::getX() {
	return _x;
}

int Enemy::getY(){
	return _y;
}
