#include<iostream>
#include<Windows.h>
#include<random>



void ShowResult(int roll, int userGuess) {
	std::cout << "出目は " << roll + 1 << " です。" << std::endl;
	if ((roll % 2 == 0 && userGuess == 1) || (roll % 2 == 1 && userGuess == 0)) {

		std::cout << "あなたの勝ちです！" << std::endl;
	} else {
		std::cout << "あなたの負けです！" << std::endl;
	}
}

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	Sleep(delayMs);
	ShowResult(roll, userGuess);
}

int main() {
	std::cout << "半か丁か(半:1,丁:0と入力)" << std::endl;
	int userChoice = scanf_s("%d", &userChoice);
	srand((unsigned)time(NULL));
	int roll = rand() % 6;
	DelayReveal(ShowResult, 3000, roll, userChoice);
	return 0;
}