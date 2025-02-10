#include"ClearScene.h"
#include"SceneManager.h"
#include<Novice.h>

void ClearScene::Initialize()
{

}

void ClearScene::Update()
{
	if (keyBord->IsTrigger(DIK_RETURN)) {
		SceneManager::Instance()->ChangeScene("Title");
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "currentScene : Clear");
}

void ClearScene::Exit()
{

}