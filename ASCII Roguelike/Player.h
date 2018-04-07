#pragma once

class Player {

public:

	Player();

	int modPlayerHealth(int mod);

	bool movePlayer(int x, int y, char type);
	int getPlayerX() { return _playerX; };
	int getPlayerY() { return _playerY; };
	void setPlayerX(int x) { _playerX = x; };
	void setPlayerY(int y) { _playerY = y; };

private:

	int _playerX;
	int _playerY;
	int _health;
	int _maxHealth;
	int _gold;

};

