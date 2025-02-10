#pragma once
#include"Scene.h"

class ClearScene : public Scene {
public:
	ClearScene() : Scene() {};
	~ClearScene() = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Exit() override;
};