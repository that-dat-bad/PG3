#include "Novice.h"
#include "Player.h"
#include "Command.h"

class InputHandle {
public:
	Command* HandleInput(const char keys[]) {
		if (keys[DIK_RIGHT]||keys[DIK_D]) {
			return buttonD_;
		}
		if (keys[DIK_LEFT]||keys[DIK_A]) {
			return buttonA_;
		}
		return nullptr;
	}

	InputHandle() {
		buttonD_ = new MoveRightCommand();
		buttonA_ = new MoveLeftCommand();
	}

	~InputHandle() {
		delete buttonD_;
		delete buttonA_;
	}

private:
	Command* buttonD_;
	Command* buttonA_;
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Novice::Initialize("Command Pattern Test", 1280, 720);

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player player;
	InputHandle inputHandler; // 入力管理クラス

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/// ↓更新処理


		Command* command = inputHandler.HandleInput(keys);


		if (command) {
			command->Execute(player);
		}


		player.Update();

		/// ↑更新処理

		/// ↓描画処理
		player.Draw();
		/// ↑描画処理

		Novice::EndFrame();
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) break;
	}

	Novice::Finalize();
	return 0;
}