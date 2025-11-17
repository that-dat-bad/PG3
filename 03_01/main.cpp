#include<iostream>
#include"Enemy.h"
int main() {
	std::cout << "Enterキーを押すと敵の行動が変化します。" << std::endl;
	Enemy *enemy = new Enemy();
	while (true) {
		enemy->Update();
	}
	return 0;
}