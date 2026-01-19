#include<iostream>

template <typename T>

T Min(T a, T b) {
	if (a <= b) {
		return a;
	} else {
		return b;
	}
}

int main() {
	int IntNum = 100;
	float FloatNum = 20.5f;
	double DoubleNum = 30.99;
	std::cout << Min<float>(IntNum, FloatNum) << std::endl;
	std::cout << Min<double>(IntNum, DoubleNum) << std::endl;
	std::cout << Min<double>(FloatNum, DoubleNum) << std::endl;
	return 0;

}