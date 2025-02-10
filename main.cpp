#include <Novice.h>
#include"SceneManager.h"

const char kWindowTitle[] = "GC1A_10_リ_ショウコウ";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	KeyBoardInput* keyBord = KeyBoardInput::Instance();
	SceneManager* scene = SceneManager::Instance();
	const std::string sceneNames[4] = {
		"Title","Play","GameOver","Clear"
	};
	int sceneCount = 0;

	scene->Initialize(sceneNames[0], std::make_shared<TitleScene>());
	scene->Initialize(sceneNames[1], std::make_shared<PlayScene>());
	scene->Initialize(sceneNames[2], std::make_shared<GameOverScene>());
	scene->Initialize(sceneNames[3], std::make_shared<ClearScene>());
	scene->ChangeScene(sceneNames[sceneCount]);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		keyBord->Update();
		///
		/// ↓更新処理ここから
		///
#ifdef _DEBUG
		//シーン切り替え（DEBUG用）
		/*if (keyBord->IsTrigger(DIK_RETURN)) {
			sceneCount++;
			if (sceneCount >= sizeof(sceneNames) / sizeof(sceneNames[0])) {
				sceneCount = 0;
			}
			scene->ChangeScene(sceneNames[sceneCount]);
		}*/
#endif // _DEBUG

		
		scene->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		scene->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (keyBord->IsTrigger(DIK_ESCAPE)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
