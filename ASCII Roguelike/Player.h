#pragma once

class Player {

public:

	Player();

	int modPlayerHealth(int mod);

	int getPlayerX() { return _coordinates[0]; };
	int getPlayerY() { return _coordinates[1]; };

private:

	int _coordinates[2];
	int _health;
	int _maxHealth;
	int _gold;

};

