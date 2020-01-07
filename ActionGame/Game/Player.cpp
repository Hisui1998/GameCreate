#include "Player.h"
#include "ResourceMng.h"
#include "Scene.h"

constexpr float speed = 3.0f;

//プレイヤー移動
// idleFlag 停止させるかさせないか
int Player::StateMove(void)
{
	if (CheckHitKey(_config->GetKey("Up")))			//ジャンプ
	{
		pos.y -= speed;
	}
	if (CheckHitKey(_config->GetKey("Down")))		//しゃがみ
	{
		pos.y += speed;
	}
	if (CheckHitKey(_config->GetKey("Left")))		//左移動
	{
		idleFlag = false;
		pos.x -= speed;
	}
	else if (CheckHitKey(_config->GetKey("Right")))	//右移動
	{
		idleFlag = false;
		pos.x += speed;
	}
	else
	{
		idleFlag = true;							//停止状態へ
	}

	if (CheckHitKey(_config->GetKey("Attack")))		//攻撃
	{
	}

	return 0;
}

//ジャンプ※多分消す
int Player::StateJump(void)
{
	return 0;
}

//落下
int Player::StateFall(void)
{
	return 0;
}

//近接攻撃
int Player::StateAttack(void)
{
	return 0;
}

//遠距離攻撃
int Player::StateShot(void)
{
	return 0;
}

//コンストラクタ
Player::Player()
{
	Init();
}

//デストラクタ
Player::~Player()
{
}

//初期化
bool Player::Init()
{
	//リソース初期化
	_images[0] = ResourceMng::Get()->GetID("../Resource/Player/player.png", { 80, 96 }, { 10, 2 });	//通常
	_images[1] = ResourceMng::Get()->GetID("../Resource/Player/walk.png", { 80, 96 }, { 10, 2 });	//歩き
	_animCnt = 0;

	//適当なプレイイヤーの位置
	pos = { 40, 500 };
	idleFlag = false;

	//関数ポインタ
	_state = ANIM_STATE::MOVE;
	stateTbl[static_cast<int>(ANIM_STATE::MOVE)] = &Player::StateMove;
	stateTbl[static_cast<int>(ANIM_STATE::FALL)] = &Player::StateFall;
	stateTbl[static_cast<int>(ANIM_STATE::SHORT_RANGE_ATK)] = &Player::StateAttack;
	stateTbl[static_cast<int>(ANIM_STATE::RANGE_ATK)] = &Player::StateShot;

	_config = std::make_shared<Config>();

	return false;
}

//更新
void Player::UpDate(char* key)
{
	_key = key;
	(this->*stateTbl[static_cast<int>(_state)])();
}

//プレイヤー描画
void Player::Draw()
{
	//_images配列の中は（(_animCnt++/フレーム数)%描画したいアニメーション数

	if (CheckHitKey(_config->GetKey("Right")))		//右向きアニメーション
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, false);
	}
	else if (CheckHitKey(_config->GetKey("Left")))	//左向きアニメーション
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, true);
	}

	if (idleFlag == true)							//停止アニメーション
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[0][(_animCnt++ / 5) % 12], true);
	}
}