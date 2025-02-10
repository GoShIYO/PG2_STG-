#include "Enemy.h"
#include<Novice.h>

Enemy::Enemy(const Vector2& position) :Object(position) {
	velocity = { 3.0f,0.0f };
	color = 0x0000ccff;
	coolDownMax = 25;
	isShoot = true;
	shootCooldown = coolDownMax;
	respawnTimer = respawnMax;
	damage = 20;

	InitCollider();
}

void Enemy::Update()
{
	Move();
	Shoot();
	collider->Update(position);

	if (hp <= 0) {
		isAlive = false;
		isShoot = false;
		CollisionManager::Instance()->RemoveCollisionBox(collider);
	}
	if (!isAlive && respawnTimer > 0) {
		--respawnTimer;
        if (respawnTimer == 0) {
			hp = 100;
			isAlive = true;
			isShoot = true;
			respawnTimer = respawnMax;
			InitCollider();
		}
	}
}

void Enemy::Move()
{
	if(!isAlive)return;
	position += velocity;
	if (position.x + radius > kWindowWidth || position.x - radius < 0)velocity.x *= -1;
	if (position.y + radius > kWindowHeight || position.y - radius < 0)velocity.y *= -1;
}

void Enemy::Shoot()
{
	Object::Shoot();
}

void Enemy::Draw()
{
	for (auto& bullet : bullets) {
		bullet->Draw();
	}
	if (isAlive) {
		int hpBarSize = int(radius) * 2;
		Novice::DrawBox(
			static_cast<int>(position.x - hpBarSize / 2.0f), static_cast<int>(position.y - radius - 15),
			hpBarSize, hpBarSize / 3, 0, WHITE, kFillModeWireFrame);
		Novice::DrawBox(
			static_cast<int>(position.x - hpBarSize / 2.0f), static_cast<int>(position.y - radius - 15),
			hpBarSize * hp / 100, hpBarSize / 3, 0, RED, kFillModeSolid);
		Novice::DrawEllipse(
			static_cast<int>(position.x), static_cast<int>(position.y),
			static_cast<int>(radius), static_cast<int>(radius),
			0.0f, color, kFillModeSolid
		);
	}
}

void Enemy::OnCollision(CollisionBox* other)
{
	if (other->GetType() == CollisionType::PlayerBullet) {
        DecreaseHp(other->GetDamage());
	}
}

void Enemy::InitCollider()
{
	collider = new CollisionBox(damage, radius, CollisionType::Enemy);
	collider->SetCallback([&](CollisionBox* other) {
		if (other->GetType() == CollisionType::PlayerBullet) {
			DecreaseHp(other->GetDamage());
		}
		});
	CollisionManager::Instance()->RegisterCollisionBox(collider);
}

void Enemy::CreateBullet()
{
	Bullet* newBullet = new Bullet(damage, CollisionType::EnemyBullet, position,Vector2(0.0f,10.0f));
	bullets.push_back(newBullet);
}
