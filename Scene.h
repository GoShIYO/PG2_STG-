#pragma once
#include<memory>
#include"Player.h"
#include"Enemy.h"
#include"KeyBoardInput.h"

class Scene {
public:
	Scene() {
		keyBord = KeyBoardInput::Instance();
	};
	virtual ~Scene() = default;
	/// <summary>
	/// シーン初期化
	/// </summary>
	virtual void Initialize() = 0;
	/// <summary>
	/// シーン更新処理
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// シーン描画処理
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// シーン退出
	/// </summary>
	virtual void Exit() = 0;
protected:
	KeyBoardInput* keyBord = nullptr;
};