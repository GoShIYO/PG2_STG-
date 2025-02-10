#pragma once
#include"TitleScene.h"
#include"PlayScene.h"
#include"GameOverScene.h"
#include"ClearScene.h"
#include<memory>
#include<unordered_map>
#include<string>

class SceneManager {
public:
	static SceneManager* Instance() {
		static SceneManager instance;
		return &instance;
	}
	/// <summary>
	/// シーンの初期化
	/// </summary>
	/// <param name="sceneName">シーンの名前</param>
	/// <param name="scene">シーンのポインター</param>
	void Initialize(const std::string& sceneName, std::shared_ptr<Scene>scene);
	/// <summary>
	/// シーンを変わる関数
	/// </summary>
	/// <param name="sceneName">変わるシーンの名前</param>
	void ChangeScene(const std::string& sceneName);
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
private:
	SceneManager() = default;
	~SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
private:
	std::shared_ptr<Scene>currentScene = nullptr;					//現在のシーン
	std::unordered_map<std::string, std::shared_ptr<Scene>>scenes;	//シーンを保存するハッシュマップ
};