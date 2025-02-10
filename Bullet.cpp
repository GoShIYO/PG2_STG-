#include "Bullet.h"
#include"Object.h"
#include"CollisionManager.h"
#include<Novice.h>

Bullet::Bullet(int damage, CollisionType type, const Vector2& position, const Vector2& velocity)
	: type(type), position(position), velocity(velocity), radius(8.0f), color(0xcc00ccff), damage(damage) {
	collider = new CollisionBox(damage, radius, type);
	// コールバック関数を登録
	collider->SetCallback([&](CollisionBox* other) {
		OnCollision(other);
		});
	// コライダーを登録
	CollisionManager::Instance()->RegisterCollisionBox(collider);
}

void Bullet::Update()
{
	position += velocity;
	collider->Update(position);
}

void Bullet::Draw()
{
	Novice::DrawEllipse(
		static_cast<int>(position.x), static_cast<int>(position.y),
		static_cast<int>(radius), static_cast<int>(radius),
		0.0f, color, kFillModeSolid
	);
}

void Bullet::OnCollision(CollisionBox* other)
{
	if (type == CollisionType::PlayerBullet && other->GetType() == CollisionType::Player)return;

	if ((type == CollisionType::PlayerBullet && other->GetType() == CollisionType::Enemy) ||
		(type == CollisionType::EnemyBullet && other->GetType() == CollisionType::Player))
	{
		isHit = true;
	}
}