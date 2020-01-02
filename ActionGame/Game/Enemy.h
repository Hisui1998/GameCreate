#pragma once
#include "PrtEnemy.h"

enum class StateID
{
	IDLE,
	MOVE,
	FALL,
	PROXATK,
	SHOTATK,
	MAX
};

class Enemy :
	public PrtEnemy
{
private:
	//関数ポインタ
	int StateIdle(void);
	int StateMove(void);
	int StateFall(void);
	int StateProx(void);
	int StateShot(void);

	int (Enemy::*stateTbl[static_cast<int>(StateID::MAX)])(void);
	//攻撃中かどうか
	bool isAttack;
	//攻撃のアニメーション数
	int atkCount;

public:
	Enemy();
	Enemy(Vec2 pos, Vec2 size);
	~Enemy();

	//オーバーライド関数群
	bool Init(void) override;
	void UpDate(char* key) override;
	void Draw(void)override;
	void CheckBlock(bool,bool, const float&, const float&)override;

	StateID state;
};

