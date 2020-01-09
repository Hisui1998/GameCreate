#pragma once
#include "Actor.h"
#include "Player.h"
#include <vector>
#include <memory>


enum class ENEMY_STATE
{
	IDLE,				//通常
	MOVE,				//歩き
	SHORT_RANGE_ATK,	//近接攻撃
	LONG_RANGE_ATK,			//遠距離攻撃
	MAX
};


class TestEnemy :
	public Actor
{
private:
	//関数ポインタでの状態遷移
	int StateIdle(void);
	int StateMove(void);		//挙動
	int StateJump(void);		//ジャンプ
	int StateAttack(void);		//近接攻撃
	int StateShot(void);		//遠距離攻撃

	int (TestEnemy::* stateTbl[static_cast<int>(ENEMY_STATE::MAX)])(void);

	ENEMY_STATE _state;

	Vec2 pos;			//座標
	RECT _hitBox;		// 当たり矩形
	RECT _attackBox;	// 当たり矩形
	int _animCnt;
	bool _deathFlag;

	std::vector<int> _images[(int)ENEMY_STATE::MAX];
	std::vector<int> _animFlame;

	std::shared_ptr<Actor> _player;

public:
	TestEnemy(std::shared_ptr<Actor> player);
	~TestEnemy();

	bool Init()override final;
	void UpDate(char* key)override final;
	void Draw()override final;

	void CheckHitBox(const RECT &rect, Vec2 pos);

	Vec2 GetPos() { return pos; };
	void SetPos(Vec2 inpos) { pos = inpos; }
};

