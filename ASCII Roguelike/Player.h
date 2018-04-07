#pragma once

#include <vector>

class Player {

public:

	Player();

	int modPlayerHealth(int mod);
	int checkPos(std::vector<std::string> levelVector);
	void movePlayer(int x, int y, char type);
	
	//getters

	int getPlayerX() { return _playerX; };
	int getPlayerY() { return _playerY; };
	
	//setters
	
	void setPlayerX(int x) { _playerX = x; };
	void setPlayerY(int y) { _playerY = y; };

private:

	int _playerX;
	int _playerY;
	int _health;
	int _maxHealth;
	int _gold;

};

