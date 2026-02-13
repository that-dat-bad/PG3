#include <Novice.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

// グローバル変数
std::vector<std::vector<int>> g_MapData;
std::mutex g_Mtx;
std::atomic<bool> g_IsLoaded(false);

// 定数
const int kWindowWidth = 1280;
const int kWindowHeight = 720;
const int kTileSize = 64;

// CSV読み込み関数
void LoadMapCSV(const std::string& filename) {
	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::ifstream file(filename);
	if (!file.is_open()) {
		// 開けなかった場合でも読み込み完了
		g_IsLoaded.store(true);
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
			} catch (...) {
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

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	{
		std::ofstream dummy("level_data.csv");
		dummy << "1,1,1,1,1\n";
		dummy << "1,0,0,2,1\n";
		dummy << "1,0,1,0,1\n";
		dummy << "1,0,0,0,1\n";
		dummy << "1,1,1,1,1\n";
	}

	Novice::Initialize("06-02", kWindowWidth, kWindowHeight);

	// スレッド起動：ロード開始
	std::thread loaderThread(LoadMapCSV, "level_data.csv");

	bool isThreadJoined = false;

	// メインループ
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		if (g_IsLoaded.load()) {
			// ロード完了後の処理

			// スレッドのjoin
			if (!isThreadJoined) {
				if (loaderThread.joinable()) {
					loaderThread.join();
				}
				isThreadJoined = true;
			}

			// マップ描画
			int y = 0;
			for (const auto& row : g_MapData) {
				int x = 0;
				for (int cell : row) {
					int outputX = x * kTileSize;
					int outputY = y * kTileSize;
					
					switch (cell) {
					case 0: // 床
						Novice::DrawBox(outputX, outputY, kTileSize, kTileSize, 0.0f, 0x444444FF, kFillModeSolid);
						break;
					case 1: // 壁
						Novice::DrawBox(outputX, outputY, kTileSize, kTileSize, 0.0f, WHITE, kFillModeSolid);
						break;
					case 2: // プレイヤー
						Novice::DrawBox(outputX, outputY, kTileSize, kTileSize, 0.0f, RED, kFillModeSolid);
						break;
					}
					x++;
				}
				y++;
			}

			Novice::ScreenPrintf(10, 10, "Load Complete. Press ESC to Exit.");

		} else {
			// ロード中の処理
			Novice::ScreenPrintf(600, 350, "Loading...");
			static int frameTimer = 0;
			frameTimer++;
			int barWidth = (frameTimer % 60) * 2;
			Novice::DrawBox(600, 370, barWidth, 10, 0.0f, BLUE, kFillModeSolid);
		}

		Novice::EndFrame();

		if (Novice::CheckHitKey(DIK_ESCAPE)) {
			break;
		}
	}

	if (!isThreadJoined && loaderThread.joinable()) {
		loaderThread.join();
	}

	Novice::Finalize();
	return 0;
}