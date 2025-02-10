#pragma once
#include"Scene.h"

class TitleScene : public Scene {
public:
	TitleScene() : Scene() {};
	~TitleScene() = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Exit() override;
};