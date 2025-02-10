#include "SceneManager.h"

void SceneManager::Initialize(const std::string& sceneName, std::shared_ptr<Scene> scene)
{
	scenes[sceneName] = scene;
}

void SceneManager::ChangeScene(const std::string& sceneName)
{
	//前のシーンを退出してから新しいシーンに変える
	if (currentScene) {
		currentScene->Exit();
	}
	//現在シーンを新しいシーンに変更
	currentScene = scenes[sceneName];
	if (currentScene) {
		currentScene->Initialize();
	}
}

void SceneManager::Update()
{
	if (currentScene) {
		currentScene->Update();
	}
}

void SceneManager::Draw()
{
	if (currentScene) {
		currentScene->Draw();
	}
}
