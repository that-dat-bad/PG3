#include<iostream>
template <typename T1, typename T2>
class MyMath {
public:
	T1 first_;
	T2 second_;
	MyMath(T1 first, T2 second) : first_(first), second_(second) {}
	void Min() {
		if (first_ >= second_) {
			std::cout << second_ << std::endl;
		} else {
			std::cout << first_ << std::endl;
		}
	};
};

int main() {
	MyMath<int, int> m1(30, 40);
	MyMath<int, float> m2(1, 2.0f);
	MyMath<int, double> m3(3, 5.0);
	MyMath<float, float> m4(0.5f, 9.0f);
	MyMath<float, double> m5(0.4f, 5.0);
	MyMath<double, double> m6(2, 40);

	m1.Min();
	m2.Min();
	m3.Min();
	m4.Min();
	m5.Min();
	m6.Min();

	return 0;
}