#include "CollisionManager.h"


void CollisionManager::RegisterCollisionBox(CollisionBox* collider) {
	colliders.push_back(collider);
}

void CollisionManager::RemoveCollisionBox(CollisionBox* collider) {
	colliders.erase(std::remove(colliders.begin(), colliders.end(), collider), colliders.end());
}

void CollisionManager::UpdateCollision() {
	for (size_t i = 0; i < colliders.size(); ++i) {
		for (size_t j = i + 1; j < colliders.size(); ++j) {		
			CollisionBox* boxA = colliders[i];
			CollisionBox* boxB = colliders[j];
			if (IsColliding(boxA, boxB)) {
				boxA->OnCollision(boxB);
				boxB->OnCollision(boxA);
			}
		}
	}
}

void CollisionManager::DrawCollisionBox() const
{
	for (auto& collider : colliders) {
		collider->Draw();
	}
}

bool CollisionManager::IsColliding(const CollisionBox* a, const CollisionBox* b) {
	Vector2 posA = a->GetWorldPosition();
	Vector2 posB = b->GetWorldPosition();
	float dx = posA.x - posB.x;
	float dy = posA.y - posB.y;
	float distanceSq = dx * dx + dy * dy;
	float radiusSum = a->GetRadius() + b->GetRadius();
	return distanceSq <= radiusSum * radiusSum;
}