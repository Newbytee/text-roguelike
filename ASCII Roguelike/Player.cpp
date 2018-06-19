#include "Player.h"

int Player::modHealth(int mod) {
	return 0;
}

void Player::move(int x, int y) {
	_x += x;
	_y += y;
}

void Player::setX(int x) {
	_x = x;
}

void Player::setY(int y) {
	_y = y;
}

void Player::setAttack(int attack) {
	_attack = attack;
}

void Player::setHp(int hp) {
	_hp = hp;
}

void Player::setMaxHp(int maxHp) {
	_maxHp = maxHp;
}

int Player::getX() {
	return _x;
}

int Player::getY() {
	return _y;
}

int Player::getAttack() {
	return _attack;
}
