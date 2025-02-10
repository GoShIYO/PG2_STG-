#pragma once
#include <Vector2.h>
#include <functional>

enum class CollisionType {
    Player,
    Enemy,
    PlayerBullet,
    EnemyBullet
};
class CollisionBox {
public:
    // 衝突コールバック
    using CollisionCallback = std::function<void(CollisionBox*)>;

    CollisionBox(int damage,float radius,CollisionType type)
        : damage(damage), radius(radius),type(type){
    }

    // 衝突コールバックを登録する
    void SetCallback(CollisionCallback callback) { OnCollied = callback; }
    // 衝突コールバックを呼び出す
    void OnCollision(CollisionBox* other) {
        if (OnCollied) {
            OnCollied(other);
        }
    }
    // 衝突判定を行う
    void Update(const Vector2& pos) {
        position = pos;
    }
    
    Vector2 GetWorldPosition() const {
        return position;
    }

    float GetRadius() const { return radius; }
    int GetDamage() const { return damage; }
    CollisionType GetType() const { return type; }
    void Draw()const;
private:
    CollisionType type;                     // 衝突判定のタイプ
    Vector2 position = { 0 };               // オブジェクトの位置
    float radius;                           // オブジェクトの半径
    int damage = 0;                         // ダメージ
    CollisionCallback OnCollied = nullptr;  // 衝突した時のコールバック
};
