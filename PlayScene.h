#pragma once
#include"Scene.h"

class PlayScene : public Scene {
public:
	PlayScene() : Scene() {};
	~PlayScene() = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Exit() override;
private:
	void UpdatePlayer();
	void UpdateEnemy();
private:
	std::unique_ptr<Player>player;
	std::vector<std::unique_ptr<Object>>enemys;
	ParticleSystem particleSystem;
	CollisionManager* collisionManager = nullptr;
};