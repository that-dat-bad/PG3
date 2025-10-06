#include<iostream>



int ComparePay(double currentKamatuPay = 0.0, double KamatuPay = 100.0, int workingTime = 1) {
	int currentTime = workingTime;//働いた時間
	int generalPay = 1226;//一般的な賃金体系
	currentKamatuPay += KamatuPay;//かまトゥの合計賃金

	if (generalPay * currentTime < currentKamatuPay)
	{
		std::cout << "かまトゥの方が高くなるのは" << workingTime << "時間働いた後" << std::endl;
		std::cout << "かまトゥの賃金:" << currentKamatuPay << "円" << std::endl;
		std::cout << "一般的な賃金:" << generalPay * currentTime << "円" << std::endl;
		return 0;
	} else
	{
		workingTime++;
		KamatuPay = KamatuPay * 2 - 50;
		ComparePay(currentKamatuPay, KamatuPay, workingTime);
	}


}




int main() {

	ComparePay();
	return 0;
}