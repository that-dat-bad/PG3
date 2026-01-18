#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>


std::vector<std::vector<int>> g_MapData;
std::mutex g_Mtx;
std::atomic<bool> g_IsLoaded(false);

void LoadMapCSV(const std::string& filename) {
	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to open file." << std::endl;
		return;
	}

	std::vector<std::vector<int>> tempMap;
	std::string line;

	// CSVパース処理
	while (std::getline(file, line)) {
		std::vector<int> row;
		std::stringstream ss(line);
		std::string cell;
		while (std::getline(ss, cell, ',')) {
			try {
				row.push_back(std::stoi(cell));
			}
			catch (...) {
				row.push_back(0);
			}
		}
		tempMap.push_back(row);
	}

	{
		std::lock_guard<std::mutex> lock(g_Mtx);
		g_MapData = tempMap;
	}

	// 読み込み完了を通知
	g_IsLoaded.store(true);
}

// マップチップを描画
void RenderMap() {
	// データの読み取り
	std::lock_guard<std::mutex> lock(g_Mtx);

	std::cout << "\n--- MAP RENDERING ---\n";
	for (const auto& row : g_MapData) {
		for (int cell : row) {
			switch (cell) {
			case 0: std::cout << ". "; break; // 床
			case 1: std::cout << "##"; break; // 壁
			case 2: std::cout << "P "; break; // プレイヤー
			default: std::cout << "??"; break;
			}
		}
		std::cout << std::endl;
	}
}

int main() {
	{
		std::ofstream dummy("level_data.csv");
		dummy << "1,1,1,1,1\n";
		dummy << "1,0,0,2,1\n";
		dummy << "1,0,1,0,1\n";
		dummy << "1,0,0,0,1\n";
		dummy << "1,1,1,1,1\n";
	}

	std::cout << "Loading map in background..." << std::endl;

	std::thread loaderThread(LoadMapCSV, "level_data.csv");

	loaderThread.join();

	std::cout << "\n Load Complete! Switching to Game Screen." << std::endl;

	RenderMap();

	return 0;
}