#include"PlayScene.h"
#include"KeyBoardInput.h"
#include"SceneManager.h"
#include<Novice.h>

void PlayScene::Initialize()
{
	player = std::make_unique<Player>(Vector2(640.0f, 360.0f));
	enemys.push_back(std::make_unique<Enemy>(Vector2(425.0f, 200.0f)));
	enemys.push_back(std::make_unique<Enemy>(Vector2(850.0f, 200.0f)));
	collisionManager = CollisionManager::Instance();
}

void PlayScene::Update()
{
	UpdateEnemy();
    UpdatePlayer();
	collisionManager->UpdateCollision();
	if (player->GetAlive() == false) {
        SceneManager::Instance()->ChangeScene("GameOver");
	}
}

void PlayScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "currentScene : Play");

	//敵描画
	for (auto& enemy : enemys) {
		enemy->Draw();
	}
	//プレイヤー描画
	player->Draw();
	collisionManager->DrawCollisionBox();
}

void PlayScene::Exit()
{
	enemys.clear();
}

void PlayScene::UpdatePlayer()
{
	//プレイヤー更新処理
	player->Update();
}

void PlayScene::UpdateEnemy()
{
	//敵更新処理
	for (auto& enemy : enemys) {
		enemy->Update();
		if (enemy->IsDeath()) {
			particleSystem.Initialize(enemy->GetPosition());
		}
	}
}
