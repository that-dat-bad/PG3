#include "Enemy.h"
#include <iostream>
#include <stdio.h>

void(Enemy::* Enemy::stateFunc[])() {
		& Enemy::Approach,
		& Enemy::Attack,
		& Enemy::Retreat
};


void Enemy::Update()
{
	(this->*stateFunc[phase_])();

	char userInput = 0;

	if (scanf_s("%c", &userInput, 1) == 1)
	{
		// 次のフェーズに進む
		phase_ = (phase_ + 1) % 3;

		if (userInput != '\n')
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
	}
}

void Enemy::Approach()
{
	std::cout << "敵が接近中" << std::endl;
}

void Enemy::Attack()
{
	std::cout << "敵が攻撃!" << std::endl;
}

void Enemy::Retreat()
{
	std::cout << "敵が退却!" << std::endl;
}
