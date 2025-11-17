#include<iostream>
#include<Windows.h>
#include<random>
#include<functional>

void DelayReveal(std::function<void(int, int)> revealFunc, unsigned int delayMs, int roll, int userGuess) {
	std::cout << "処理中..." << std::endl;
	Sleep(delayMs);
	revealFunc(roll, userGuess);
}

int main() {
	std::cout << "半か丁か(半:1,丁:0と入力)" << std::endl;
	int userChoice = 0;
	scanf_s("%d", &userChoice);


	srand((unsigned)time(NULL));
	int roll = rand() % 6;

	DelayReveal(
		[](int r, int ug) {
			std::cout << "出目は " << r + 1 << " です。" << std::endl;
			if ((r % 2 == 0 && ug == 1) || (r % 2 == 1 && ug == 0)) {
				std::cout << "あなたの勝ちです！" << std::endl;
			} else {
				std::cout << "あなたの負けです！" << std::endl;
			}
		},
		3000, roll, userChoice);

	return 0;
}