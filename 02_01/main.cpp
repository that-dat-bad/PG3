#include<iostream>

template<typename Type1, typename Type2, typename Type3>

Type1 Min(Type2 a, Type3 b) {
	if (a <= b)
	{
		return static_cast<Type1>(a);
	} else {
		return static_cast<Type1>(b);
	}
}

int main() {
	int IntNum = 100;
	float FloatNum = 20.5f;
	double DoubleNum = 30.99;
	std::cout << Min<float ,int,float>(IntNum, FloatNum) << std::endl;
	std::cout << Min<double, int, double>(IntNum, DoubleNum) << std::endl;
	std::cout << Min<double, float, double>(FloatNum, DoubleNum) << std::endl;
	return 0;

}