#pragma once
#include"Object.h"
#include"KeyBoardInput.h"

class Player : public Object  {
public:
	Player(const Vector2& position);
	~Player() = default;

	void Update()override;
	void Shoot()override;
	void Draw()override;
	void InitCollider()override;
	void OnCollision(CollisionBox* other)override;
private:
	void CreateBullet()override;
	void Move();
private:
	KeyBoardInput* keyBord; //キーボード入力インスタンス
	int invincibleTimer = 60;
};