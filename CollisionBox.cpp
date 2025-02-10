#include "CollisionBox.h"
#include<Novice.h>

void CollisionBox::Draw() const
{
	Novice::DrawBox(
		static_cast<int>(GetWorldPosition().x - GetRadius()),
		static_cast<int>(GetWorldPosition().y - GetRadius()),
		static_cast<int>(GetRadius() * 2),
		static_cast<int>(GetRadius() * 2),
		0.0f,
		0x00ffffff,
		kFillModeWireFrame
	);
}
