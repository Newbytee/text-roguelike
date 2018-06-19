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
	if (mod < _hp) {
		_hp -= mod;
		return 0;
	} else if (mod == _hp) {
		return 1;
	} else {
		return 2;
	}
}

void Enemy::setX(int x) {
	_x = x;
}

void Enemy::setY(int y) {
	_y = y;
}

void Enemy::setAttack(int attack) {
	_attack = attack;
}

int Enemy::getX() {
	return _x;
}

int Enemy::getY(){
	return _y;
}

int Enemy::getAttack() {
	return _attack;
}
