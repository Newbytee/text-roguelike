#pragma once

class Player {
public:
	int modHealth(int mod);
	void setX(int x);
	void setY(int y);

	int getX();
	int getY();
private:
	int _x;
	int _y;
	int _hp;
	int _maxHp;
	int _gold;
};