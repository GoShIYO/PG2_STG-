#include"Player.h"
#include<Novice.h>

Player::Player(const Vector2& position) :Object(position) {
	velocity = { 5.0f,5.0f };
	color = 0x802166ff;
	coolDownMax = 8;
	shootCooldown = coolDownMax;
	damage = 10;
	keyBord = KeyBoardInput::Instance();

	InitCollider();
}

void Player::Update()
{
	Move();
	Shoot();
	particle.Update();
	collider->Update(position);

	// ダメージを受けたときの処理
	if (isHurt) {
		if (invincibleTimer > 0) {
            invincibleTimer--;
		}
		else {
			isHurt = false;
			invincibleTimer = 60;
		}
		color = 0xcc0000ff;
	}
	else {
		color = 0x802166ff;
	}
	if (hp <= 0) {
		isAlive = false;
	}
	Novice::ScreenPrintf(0, 20, "%d", isHurt);
	Novice::ScreenPrintf(0, 40, "PLAYER HP : %d", hp);
}

void Player::CreateBullet()
{
	Bullet* newBullet = new Bullet(damage,CollisionType::PlayerBullet, position);
	bullets.push_back(newBullet);
}

void Player::Move()
{
	if (keyBord->IsPress(DIK_UP))position.y -= velocity.y;
	if (keyBord->IsPress(DIK_DOWN))position.y += velocity.y;
	if (keyBord->IsPress(DIK_LEFT))position.x -= velocity.x;
	if (keyBord->IsPress(DIK_RIGHT))position.x += velocity.x;
}

void Player::Shoot()
{
	isShoot = false;
	if (keyBord->IsPress(DIK_SPACE)) {
		isShoot = true;
	}
	Object::Shoot();
}

void Player::Draw()
{
	for (auto& bullet : bullets) {
		bullet->Draw();
	}
	if (isHurt) {
		if (invincibleTimer % 8 == 0) {
			Novice::DrawEllipse(
				static_cast<int>(position.x), static_cast<int>(position.y),
				static_cast<int>(radius), static_cast<int>(radius),
				0.0f, color, kFillModeSolid
			);
		}
	}
	else {
		Novice::DrawEllipse(
			static_cast<int>(position.x), static_cast<int>(position.y),
			static_cast<int>(radius), static_cast<int>(radius),
			0.0f, color, kFillModeSolid
		);
	}
}

void Player::InitCollider()
{
	collider = new CollisionBox(damage, radius, CollisionType::Player);
	// コールバック関数を登録
	collider->SetCallback([&](CollisionBox* other) {
		OnCollision(other);
		});
	// コリジョンマネージャーに登録
	CollisionManager::Instance()->RegisterCollisionBox(collider);
}

void Player::OnCollision(CollisionBox* other)
{
	if (isHurt)return;
	switch (other->GetType())
	{
	case CollisionType::Enemy:

		DecreaseHp(other->GetDamage());
		isHurt = true;

		break;
	case CollisionType::EnemyBullet:
		DecreaseHp(other->GetDamage());
		isHurt = true;

		break;
	default:
		break;
	}
}
