#pragma once
#include"CollisionManager.h"
#include<Vector2.h>

extern const int kWindowWidth;
extern const int kWindowHeight;

class Object;
class Bullet {
public:
	/// <summary>
	/// 弾のコンストラクタ
	/// </summary>
	/// <param name="damage">ダメージ</param>
	/// <param name="type">所属</param>
	/// <param name="position">位置</param>
	/// <param name="velocity">ベクトル</param>
	Bullet(int damage, CollisionType type, const Vector2& position, const Vector2& velocity = { 0.0f,-10.0f });
	~Bullet() {
		if (collider) {
			CollisionManager::Instance()->RemoveCollisionBox(collider);
		}
		collider = nullptr;
	};

	void Update();
	void Draw();
	bool GetHit()const { return isHit; }
	bool IsEnable() const {
		return
			position.x - radius > 0 && position.x + radius < kWindowWidth &&
			position.y - radius > 0 && position.y + radius < kWindowHeight;
	}

	Vector2 GetPosition() const { return position; }
	float GetRadius() const { return radius; }
	void SetHit(bool flag) { isHit = flag; }
	void OnCollision(CollisionBox* other);
private:
	Vector2 position;
	Vector2 velocity;
	float radius;
	int damage;
	unsigned int color;
	bool isHit = false;
	CollisionType type;
	CollisionBox* collider = nullptr;
};