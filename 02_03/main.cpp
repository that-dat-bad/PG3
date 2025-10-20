#include<iostream>
#include<Windows.h>


typedef void (*PFunc)(int*);

void DispResult(int *s){
	std::cout << "Result: " << *s << std::endl;
}

void SetTimeOut(PFunc p, int second) {
	Sleep(second * 1000);
}

int main() {
	std::cout << "Start" << std::endl;

	PFunc p;
	p = DispResult;
	SetTimeOut(p, 5);

	return 0;
}