#include <Novice.h>
#include "SceneManager.h"

const char kWindowTitle[] = "LE2B_14_タカナガ_ダイキ_PG3_04-01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// シーン管理者を生成（コンストラクタ内で初期シーンを生成して Initialize を呼ぶ）
	SceneManager sceneManager;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// 更新（SceneManager 内で IScene::PollKeys が呼ばれ、各シーンの Update が実行される）
		sceneManager.Update();

		// 描画
		sceneManager.Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーがトリガーされたらループを抜ける
		if (IScene::IsKeyTriggered(DIK_ESCAPE)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
