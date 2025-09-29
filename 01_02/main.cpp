#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include<algorithm>

using namespace std;
int main() {

	vector<string> addressList;
	ifstream inputFile("PG3_2025_01_02.txt");

	string line;
	if (std::getline(inputFile, line)) {

		stringstream ss(line);
		string email;

		while (std::getline(ss, email, ',')) {
			if (!email.empty()) {
				addressList.push_back(email);
			}
		}
	}
	sort(addressList.begin(), addressList.end());
	for (const auto& email : addressList) {
		cout << email << endl;
	}

}