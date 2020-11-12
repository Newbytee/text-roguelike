#include "Enemy.h"

Enemy::Enemy() = default;

Enemy::Enemy(int x, int y, int attack, int hp, int maxHp) {
	_x = x;
	_y = y;
	_attack = attack;
	_hp = hp;
	_maxHp = maxHp;
}

void Enemy::modHealth(int mod) {
	_hp -= mod;
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

void Enemy::setHp(int hp) {
	_hp = hp;
}

void Enemy::setMaxHp(int maxHp) {
	_maxHp = maxHp;
}

void Enemy::move(int x, int y) {
	_x += x;
	_y += y;
}

int Enemy::getX() {
	return _x;
}

int Enemy::getY(){
	return _y;
}

int Enemy::getHp() {
	return _hp;
}

int Enemy::getAttack() {
	return _attack;
}
