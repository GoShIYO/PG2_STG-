#include "Object.h"
#include<Novice.h>

Object::Object(const Vector2& position)
	:position(position), velocity{ 0.0f,0.0f }, radius(15.0f), color(BLUE), isShoot(false), shootCooldown(0), coolDownMax(0), damage(0){
	hp = 100;
	respawnMax = 120;
	respawnTimer = 0;
}

Object::~Object() {
	bullets.clear();
	if (collider) {
		CollisionManager::Instance()->RemoveCollisionBox(collider);
	}
}

void Object::Shoot()
{
	if (isShoot && shootCooldown <= 0) {
		CreateBullet();
		shootCooldown = coolDownMax;
	}
	if (shootCooldown > 0) {
		shootCooldown--;
	}

	for (auto it = bullets.begin(); it != bullets.end();) {
		(*it)->Update();
		if ((*it)->GetHit() || !(*it)->IsEnable()) {
			delete* it;
			it = bullets.erase(it);
		}
		else {
			++it;
		}
	}
}