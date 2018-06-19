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

int Player::getX() {
	return _x;
}

int Player::getY() {
	return _y;
}