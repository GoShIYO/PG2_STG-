#pragma once
#include "CollisionBox.h"
#include <vector>
#include <algorithm>

class CollisionManager {
public:

    static CollisionManager* Instance() {
        static CollisionManager instance;
        return &instance;
    }

    // コライダーを登録
    void RegisterCollisionBox(CollisionBox* collider);
    // コライダーを削除
    void RemoveCollisionBox(CollisionBox* collider);
    // コライダーの更新
    void UpdateCollision();
    // コライダーの描画(DEBUG用)
    void DrawCollisionBox()const;
private:
    CollisionManager() = default;
    ~CollisionManager() {
        colliders.clear();
    };

    CollisionManager(const CollisionManager&) = delete;
    CollisionManager& operator=(const CollisionManager&) = delete;

    bool IsColliding(const CollisionBox* a, const CollisionBox* b);

private:
    std::vector<CollisionBox*> colliders; //コライダーのリスト
};

