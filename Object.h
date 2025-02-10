#pragma once
#include"CollisionManager.h"
#include"Bullet.h"
#include<vector2.h>
#include<vector>

class Object {
public:
	Object(const Vector2& position);
	virtual ~Object();

	virtual void Update() = 0;
	virtual void InitCollider() = 0;
	virtual void OnCollision(CollisionBox* other) = 0;

	virtual void Draw() = 0;
	virtual void Shoot();

	/// <summary>
	/// 位置を得る
	/// </summary>
	/// <returns>位置のベクトル</returns>
	Vector2 GetPosition()const { return position; }
	/// <summary>
	/// 半径をえる
	/// </summary>
	/// <returns>半径</returns>
	float GetRadius()const { return radius; }
	/// <summary>
	/// HPを減る
	/// </summary>
	/// <param name="dmg">ダメージ</param>
	void DecreaseHp(int dmg) { if (hp > 0)hp -= dmg; }
	/// <summary>
	/// オブジェクトのダメージを得る
	/// </summary>
	/// <returns>ダメージ</returns>
	int GetDamage()const { return damage; }
	/// <summary>
	///	生存フラグを得る
	/// </summary>
	/// <returns>生存フラグ</returns>
	bool GetAlive()const { return isAlive; }

	bool IsDeath()const{ return !isAlive && respawnTimer == respawnMax;}
protected:
	/// <summary>
	/// 弾を作る
	/// </summary>
	virtual void CreateBullet() = 0;
protected:
	Vector2 position;			//位置
	Vector2 velocity;			//速度
	float radius;				//半径
	unsigned int color;			//色
	int hp;						//HP
	std::vector<Bullet*>bullets; //弾の配列
	int shootCooldown;			//クールダウン
	int coolDownMax;			//クールダウンの上限
	int damage;					//ダメージ
	bool isShoot = false;		//発射フラグ
	bool isHurt = false;		//当たりフラグ
	int respawnTimer;           //リスボーンタイマー
	int respawnMax;		     	//リスボーンタイマーの最大値
	bool isAlive = true;		//生存フラグ
	CollisionBox* collider = nullptr;
};