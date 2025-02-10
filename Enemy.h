#pragma once
#include"Object.h"

class Enemy : public Object {
public:
	Enemy(const Vector2& position);
	~Enemy() = default;

	void Update()override;
	void Shoot()override;
	void Draw()override;
	void OnCollision(CollisionBox* other);
	void InitCollider()override;
protected:
	void CreateBullet()override;
private:
	 void Move();
};	