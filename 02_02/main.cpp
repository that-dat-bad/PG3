#include<iostream>



int ComparePay(double currentKamatuPay = 0.0, double KamatuPay = 100.0, double workingTime = 1.0) {

	double currentMinute = workingTime;

	const double generalPayPerMinute = 1226.0 / 60.0;
	currentKamatuPay += KamatuPay / 60.0;

	double generalTotalPay = generalPayPerMinute * currentMinute;


	if (generalTotalPay < currentKamatuPay)
	{
		double hours = (currentMinute - 1) / 60;

		std::cout << "かまトゥの方が高くなるのは" << hours << "時間働いた後" << std::endl;
		std::cout << "かまトゥの賃金:" << currentKamatuPay << "円" << std::endl;
		std::cout << "一般的な賃金:" << generalTotalPay << "円" << std::endl;
		return 0;
	} else
	{
		double nextKamatuHourlyPay = KamatuPay;

		if (static_cast<int>(currentMinute) % 60 == 0) {
			nextKamatuHourlyPay = KamatuPay * 2 - 50;
		}

		return ComparePay(currentKamatuPay, nextKamatuHourlyPay, currentMinute + 1.0);
	}
}




int main() {

	ComparePay();
	return 0;
}