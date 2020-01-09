#pragma once
#include "Actor.h"
#include "Config.h"
#include <memory>
#include <map>
#include <string>
#include <vector>

//----------------------------------------------
//プレイヤークラス
//----------------------------------------------

enum class ANIM_STATE
{
	MOVE,				//移動
	JUMP,				//ジャンプ
	FALL,				//落下
	SHORT_RANGE_ATK,	//近接攻撃
	RANGE_ATK,			//遠距離攻撃
	MAX
};


class Player :
	public Actor
{
private:
	//関数ポインタでの状態遷移
	int StateMove(void);		//挙動
	int StateJump(void);		//ジャンプ
	int StateFall(void);		//落下
	int StateAttack(void);		//近接攻撃
	int StateShot(void);		//遠距離攻撃

	int (Player::* stateTbl[static_cast<int>(ANIM_STATE::MAX)])(void);

	ANIM_STATE _state;
	Vec2 pos;		//プレイヤー座標
	Vec2 temp, prev;

	bool _turnFlag;
	bool _idleFlag;	//停止フラグ
	bool _isJump;
	int _animCnt;	//アニメーションカウント
	float _vecx, _vecy;
	//float speed;

	//リソース格納用
	std::vector<int> _images[3];
	std::vector<int> _image;
	//コンフィグ
	std::shared_ptr<Config> _config;

public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	//初期化
	bool Init()override final;
	//更新
	void UpDate(char* key)override final;
	//描画用
	void Draw()override final;

	Vec2 GetPos() { return pos; };
	void SetPos(Vec2 inpos) { pos = inpos; };
};

