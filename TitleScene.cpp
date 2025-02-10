#include"TitleScene.h"
#include"SceneManager.h"
#include<Novice.h>

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	if (keyBord->IsTrigger(DIK_RETURN)) {
		SceneManager::Instance()->ChangeScene("Play");
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "currentScene : Title");
}

void TitleScene::Exit()
{
}