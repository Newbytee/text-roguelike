#pragma once

class Enemy {	
public:
	Enemy();
	Enemy(int x, int y, int hp, int maxHp);

	int modHealth(int mod);
	void setX(int x);
	void setY(int y);
	void setAttack(int attack);
	int getX();
	int getY();
	int getAttack();
private:
	int _x;
	int _y;
	int _attack;
	int _hp;
	int _maxHp;
};