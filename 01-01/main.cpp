#include <iostream>
#include <list>
#include <string>

int main() {
	std::list<std::string> YamanoteLine = { "Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
		"Uguisudani","Nippori","Tabata","Komagome",
		"Sugamo","Otsuka","Ikebukuro","Mejiro","Takadanobaba",
		"Shin-Okubo","Shinjuku","Yoyogi","Harajuku","Shibuya",
		"Ebisu","Meguro","Gotanda","Osaki","Shinagawa",
		"Tamachi","Hamamatsucho","Shimbashi","Yurakucho" };

	std::cout << "in 1970" << std::endl;
	for (auto itr = YamanoteLine.begin(); itr != YamanoteLine.end(); ++itr) {
		std::cout << *itr;
		if (std::next(itr) != YamanoteLine.end()) {
			std::cout << ",";
		}
	}
	std::cout << std::endl;


	for (auto itr = YamanoteLine.begin(); itr != YamanoteLine.end(); ++itr) {
		if (*itr == "Tabata") {
			YamanoteLine.insert(itr, "Nishi-Nippori");
			break;
		}
	}

	std::cout << "\nin 2019" << std::endl;
	for (auto itr = YamanoteLine.begin(); itr != YamanoteLine.end(); ++itr) {
		std::cout << *itr;
		if (std::next(itr) != YamanoteLine.end()) {
			std::cout << ",";
		}
	}
	std::cout << std::endl;

	for (auto itr = YamanoteLine.begin(); itr != YamanoteLine.end(); ++itr) {
		if (*itr == "Tamachi") {
			YamanoteLine.insert(itr, "Takanawa Gateway");
			break;
		}
	}

	std::cout << "\nin 2022" << std::endl;
	for (auto itr = YamanoteLine.begin(); itr != YamanoteLine.end(); ++itr) {
		std::cout << *itr;
		if (std::next(itr) != YamanoteLine.end()) {
			std::cout << ",";
		}
	}

	return 0;
}