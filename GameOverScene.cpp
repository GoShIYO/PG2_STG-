#include"GameOverScene.h"
#include"SceneManager.h"
#include<Novice.h>

void GameOverScene::Initialize()
{

}

void GameOverScene::Update()
{
	if (keyBord->IsTrigger(DIK_RETURN)) {
		SceneManager::Instance()->ChangeScene("Title");
	}
}

void GameOverScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "currentScene : GameOver");
}

void GameOverScene::Exit()
{

}