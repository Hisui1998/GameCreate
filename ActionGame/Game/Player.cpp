#include "Player.h"
#include "ResourceMng.h"
#include "Scene.h"

constexpr float speed = 3.0f;

//プレイヤー移動
// _idleFlag 停止させるかさせないか
int Player::StateMove(void)
{
	
	if (CheckHitKey(_config->GetKey("Up")))				//ジャンプ
	{
		if (!_isJump)
		{
			_isAerial = true;
			_state = ANIM_STATE::JUMP;
		}
		_isJump = true;
		
	}
	else if (CheckHitKey(_config->GetKey("Down")))		//しゃがみ
	{
		_idleFlag = false;
	}
	else if (CheckHitKey(_config->GetKey("Left")))		//左移動
	{
		_idleFlag = false;
		pos.x -= speed;
	}
	else if (CheckHitKey(_config->GetKey("Right")))		//右移動
	{
		_idleFlag = false;
		pos.x += speed;
	}
	else
	{
		_idleFlag  = true;								//停止状態へ
	}

	if (CheckHitKey(_config->GetKey("Attack")))			//攻撃
	{	
	}

	return 0;
}

//ジャンプ処理
int Player::StateJump(void)
{
	if (_isJump == true)
	{
		temp.y = pos.y;
		pos.y += (pos.y - prev.y) + 1;
		prev.y = temp.y;
		if (pos.y >= 450) _isJump = false;
	}
	else
	{
		_state = ANIM_STATE::MOVE;
	}

	if (CheckHitKey(_config->GetKey("Up")) && _isJump == false)
	{
		_isJump = true;
		prev.y = pos.y;
		pos.y = pos.y - 20;
	}
	

	
	return 0;
}

//落下
int Player::StateFall(void)
{
	pos.y += 0.3f;
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
	//OnInit(_vecx, _vecy);

	//リソース初期化	
	_images[0] = ResourceMng::Get()->GetID("../Resource/Player/player.png", { 80, 96 }, { 10, 2 });	//通常
	_images[1] = ResourceMng::Get()->GetID("../Resource/Player/walk.png", { 80, 96 }, { 10, 2 });	//歩き
	_image = ResourceMng::Get()->GetID("../Resource/Player/squat.png");	

	_animCnt = 0;

	pos = { 40, 400 };
	//pos格納用
	temp = { 0,0 };
	prev = { 0,0 };


	_idleFlag = false;
	_isJump = false;
	_isAerial = false;

	//関数ポインタ
	_state = ANIM_STATE::MOVE;
	stateTbl[static_cast<int>(ANIM_STATE::MOVE)] = &Player::StateMove;
	stateTbl[static_cast<int>(ANIM_STATE::JUMP)] = &Player::StateJump;
	stateTbl[static_cast<int>(ANIM_STATE::FALL)] = &Player::StateFall;
	stateTbl[static_cast<int>(ANIM_STATE::SHORT_RANGE_ATK)] = &Player::StateAttack;
	stateTbl[static_cast<int>(ANIM_STATE::RANGE_ATK)] = &Player::StateShot;

	//コンフィグ
	_config = std::make_shared<Config>();

	return false;
}

//更新
void Player::UpDate(char* key)
{
	(this->*stateTbl[static_cast<int>(_state)])();	

//	OnAccel(_vecx, _vecy);
//	OnMove(_vecx, _vecy);
}

//プレイヤー描画
void Player::Draw()
{
	//_images配列の中は（(_animCnt++/フレーム数)%描画したいアニメーション数

	if (CheckHitKey(_config->GetKey("Right")))		//右向きアニメーション
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, false);		
	}
	else if(CheckHitKey(_config->GetKey("Left")))	//左向きアニメーション
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, true);
	}
	else if (CheckHitKey(_config->GetKey("Down")))
	{
		for (auto &image:_image)
		{
			DrawRotaGraph(pos.x, pos.y, 1, 0, image, true, true);
		}
		
	}
	

	if (_idleFlag == true)							//停止アニメーション
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[0][(_animCnt++ / 5) % 12], true);
	}

	
}

void Player::OnInit(float& vecx, float& vecy)
{
	_isAerial = false;
	vecx = 0.0f;
}

void Player::PushJump(float& vecx, float& vecy)
{
	vecy += -0.5f;
}

void Player::OnMove(float vecx, float vecy)
{
	if (!_isAerial)return;
	pos.x += vecx;
	pos.y += vecy;
}

void Player::OnAccel(float& vecx, float& vecy)
{
	if (_isAerial)
	{
		vecx += 0.0f;
		vecy += 0.2f;
	}
}
