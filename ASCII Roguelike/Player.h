#pragma once

class Player {
public:
	int modHealth(int mod);
	void move(int x, int y);
	void setX(int x);
	void setY(int y);
	void setAttack(int attack);
	void setHp(int hp);
	void setMaxHp(int maxHp);
	int getX();
	int getY();
	int getAttack();
private:
	int _x;
	int _y;
	int _attack;
	int _hp;
	int _maxHp;
	int _gold;
};