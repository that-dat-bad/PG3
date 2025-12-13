#pragma once
class Enemy
{
public:

	void Update();

private:

	int phase_ = 0;
	void Approach();
	void Attack();
	void Retreat();
	static void(Enemy::* stateFunc[])();
};