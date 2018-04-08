#pragma once

class Enemy {

public:

	Enemy();
	Enemy(int x, int y, int health, int maxHealth);

	int modEnemyHealth(int mod);

	int getEnemyX() { return _enemyX; };
	int getEnemyY() { return _enemyY; };
	void setEnemyX(int x) { _enemyX = x; };
	void setEnemyY(int y) { _enemyY = y; };

private:

	int _enemyX;
	int _enemyY;
	int _health;
	int _maxHealth;

};