#pragma once

class Enemy {	
public:
	Enemy();
	Enemy(int x, int y, int attack, int hp, int maxHp);
	void modHealth(int mod);
	void setX(int x);
	void setY(int y);
	void setAttack(int attack);
	void setHp(int hp);
	void setMaxHp(int maxHp);
	void move(int x, int y);
	int getX();
	int getY();
	int getHp();
	int getAttack();
private:
	int _x;
	int _y;
	int _attack;
	int _hp;
	int _maxHp;
};