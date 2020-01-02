#pragma once
#include "PrtEnemy.h"

enum class StateID
{
	IDLE,		//停止中
	MOVE,		//移動
	FALL,		//落下
	PROXATK,	//近接攻撃
	SHOTATK,	//遠距離攻撃
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
	//位置情報、画像サイズ
	Enemy(Vec2 pos, Vec2 size);
	~Enemy();

	//オーバーライド関数群
	bool Init(void) override;
	void UpDate(char* key) override;
	void Draw(void)override;

	//地面との判定、壁との判定、変更情報x,y
	void CheckBlock(bool isGround, bool isWall, const float& x, const float& y)override;

	StateID state;
};

