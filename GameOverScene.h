#pragma once
#include"Scene.h"

class GameOverScene : public Scene {
public:
	GameOverScene() : Scene() {};
	~GameOverScene() = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Exit() override;
};