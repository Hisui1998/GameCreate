#include "Player.h"
#include "ResourceMng.h"
#include "Scene.h"

constexpr float speed = 3.0f;

//プレイヤー移動
// _idleFlag 停止させるかさせないか
int Player::StateMove(void)
{
	_idleFlag = false;
	_isJump = false;

	if (CheckHitKey(_config->GetKey("Up")))				//ジャンプへ遷移
	{
		_state = ANIM_STATE::JUMP;
	}
	else if (CheckHitKey(_config->GetKey("Down")))		//しゃがみ
	{
	}
	else if (CheckHitKey(_config->GetKey("Right")))		//右移動
	{
		_turnFlag = true;
		pos.x += speed;
	}
	else if (CheckHitKey(_config->GetKey("Left")))		//左移動
	{
		 _turnFlag = false;
		pos.x -= speed;
	}
	else
	{
		_idleFlag  = true;								//停止状態
	}

	return 0;
}

//ジャンプ処理
int Player::StateJump(void)
{
	//ジャンプしているか
	if (_isJump == true)
	{
		temp.y = pos.y;
		pos.y += (pos.y - prev.y) + 1;
		prev.y = temp.y;
		if (pos.y >= 400)
		{
			_isJump = false;
			_state = ANIM_STATE::MOVE;
		}
	}

	//ジャンプ
	if (CheckHitKey(_config->GetKey("Up")) && _isJump == false)
	{
		_isJump = true;
		prev.y = pos.y;
		pos.y = pos.y - 15;
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
	//それぞれのリソース破棄
	//for (int i = 0; i < 3; ++i)
	//{
	//	for (auto& image : _images[i])
	//	{
	//		DeleteGraph(image, true);
	//	}
	//}
}

//初期化
bool Player::Init()
{
	//リソース初期化	
	_images[0] = ResourceMng::Get()->GetID("../Resource/Player/player.png", { 80, 96 }, { 10, 2 });	//通常
	_images[1] = ResourceMng::Get()->GetID("../Resource/Player/walk.png", { 80, 96 }, { 10, 2 });	//歩き
	_images[2] = ResourceMng::Get()->GetID("../Resource/Player/jump2.png", { 80, 96 }, { 10, 2 });	//ジャンプ
	_image = ResourceMng::Get()->GetID("../Resource/Player/squat.png");								//しゃがみ

	_animCnt = 0;

	pos = { 40, 400 };
	//ジャンプするときのpos格納用
	temp = { 0,0 };
	prev = { 0,0 };

	_turnFlag = false;
	_idleFlag = false;
	_isJump = false;

	//関数ポインタ初期化
	_state = ANIM_STATE::MOVE;
	stateTbl[static_cast<int>(ANIM_STATE::MOVE)]			= &Player::StateMove;
	stateTbl[static_cast<int>(ANIM_STATE::JUMP)]			= &Player::StateJump;
	stateTbl[static_cast<int>(ANIM_STATE::FALL)]			= &Player::StateFall;
	stateTbl[static_cast<int>(ANIM_STATE::SHORT_RANGE_ATK)] = &Player::StateAttack;
	stateTbl[static_cast<int>(ANIM_STATE::RANGE_ATK)]		= &Player::StateShot;

	//コンフィグ
	_config = std::make_shared<Config>();

	return false;
}

//更新
void Player::UpDate(char* key)
{
	(this->*stateTbl[static_cast<int>(_state)])();	
}

//プレイヤー描画
void Player::Draw()
{
	//_images配列の中は（(_animCnt++/フレーム数)%描画したいアニメーション数

	//ジャンプアニメーション
	if (_isJump)												
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[2][(_animCnt++ / 3) % 13], true, false);
	}

	//しゃがみ
	else if (CheckHitKey(_config->GetKey("Down")))					
	{
		for (auto& image : _image)
		{
			DrawRotaGraph(pos.x, pos.y, 1, 0, image, true, false);
		}
	}

	//右向きアニメーション
	else if (CheckHitKey(_config->GetKey("Right")) && _turnFlag)
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, false);		
	}

	//左向きアニメーション
	else if (CheckHitKey(_config->GetKey("Left")) && !_turnFlag)
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, true);
	}
	
	//停止アニメーション
	else if (!CheckHitKeyAll() || _idleFlag)
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[0][(_animCnt++ / 5) % 12], true);
	}
}
