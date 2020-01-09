#include "Player.h"
#include "ResourceMng.h"
#include "Scene.h"

constexpr float speed = 3.0f;

//プレイヤー移動
// _idleFlag 停止させるかさせないか
int Player::StateMove(void)
{
	_state = ANIM_STATE::IDLE;
	_idleFlag = false;
	_isJump = false;

	KeyUpdate();

	return 0;
}

//ジャンプ処理
int Player::StateJump(void)
{
	KeyUpdate();
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

	_state = ANIM_STATE::MOVE;
	return 0;
}

//遠距離攻撃
int Player::StateShot(void)
{
	return 0;
}

int Player::KeyUpdate(void)
{
	if (CheckHitKey(_config->GetKey("Right")))		//右移動
	{
		if (!_isJump)
		{
			_state = ANIM_STATE::MOVE;
		}
		_turnFlag = false;
		pos.x += speed;
	}
	if (CheckHitKey(_config->GetKey("Left")))		//左移動
	{
		if (!_isJump)
		{
			_state = ANIM_STATE::MOVE;
		}
		_turnFlag = true;
		pos.x -= speed;
	}
	if (CheckHitKey(_config->GetKey("Up")))			//ジャンプへ遷移
	{
		if (!_isJump)
		{
			_isJump = true;
			prev.y = pos.y;
			pos.y = pos.y - 15;
		}
		_state = ANIM_STATE::JUMP;
	}
	if (CheckHitKey(_config->GetKey("Down")))		//しゃがみ
	{
		if (!_isJump)
		{
			_state = ANIM_STATE::CROUCH;
		}
	}
	
	if (CheckHitKey(_config->GetKey("Attack")))		//攻撃
	{
		_state = ANIM_STATE::SHORT_RANGE_ATK;
		_animCnt = 0;
	}
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
	_animFlame.resize((int)ANIM_STATE::MAX);
	//リソース初期化	
	_images[(int)ANIM_STATE::IDLE] = ResourceMng::Get()->GetID("../Resource/Player/player.png", { 80, 96 }, { 10, 2 });	//通常
	_images[(int)ANIM_STATE::MOVE] = ResourceMng::Get()->GetID("../Resource/Player/walk.png", { 80, 96 }, { 10, 2 });	//歩き
	_images[(int)ANIM_STATE::JUMP] = ResourceMng::Get()->GetID("../Resource/Player/jump2.png", { 80, 96 }, { 10, 2 });	//ジャンプ
	_images[(int)ANIM_STATE::CROUCH] = ResourceMng::Get()->GetID("../Resource/Player/squat.png");						//しゃがみ
	_images[(int)ANIM_STATE::FALL] = _images[(int)ANIM_STATE::JUMP];
	_images[(int)ANIM_STATE::SHORT_RANGE_ATK] = ResourceMng::Get()->GetID("../Resource/PlayerAttack3/tewi_material18.png", { 120, 96 }, { 6, 2 });

	_animFlame[(int)ANIM_STATE::IDLE] = 12;
	_animFlame[(int)ANIM_STATE::MOVE] = 10;
	_animFlame[(int)ANIM_STATE::JUMP] = 13;
	_animFlame[(int)ANIM_STATE::CROUCH] = 1;
	_animFlame[(int)ANIM_STATE::FALL] = 3;
	_animFlame[(int)ANIM_STATE::SHORT_RANGE_ATK] = 10;
	_animCnt = 0;

	pos = { 40, 350};
	//ジャンプするときのpos格納用
	temp = { 0,0 };
	prev = { 0,0 };

	_turnFlag = false;
	_idleFlag = false;
	_isJump = false;

	//関数ポインタ初期化
	_state = ANIM_STATE::MOVE;
	stateTbl[static_cast<int>(ANIM_STATE::IDLE)]			= &Player::StateMove;
	stateTbl[static_cast<int>(ANIM_STATE::CROUCH)]			= &Player::StateMove;
	stateTbl[static_cast<int>(ANIM_STATE::MOVE)]			= &Player::StateMove;
	stateTbl[static_cast<int>(ANIM_STATE::JUMP)]			= &Player::StateJump;
	stateTbl[static_cast<int>(ANIM_STATE::FALL)]			= &Player::StateFall;
	stateTbl[static_cast<int>(ANIM_STATE::SHORT_RANGE_ATK)] = &Player::StateAttack;
	stateTbl[static_cast<int>(ANIM_STATE::LONG_RANGE_ATK)]	= &Player::StateShot;

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
	if (_state != ANIM_STATE::FALL)
	{
		_animCnt++;
	}
	//_images配列の中は（(_animCnt++/フレーム数)%描画したいアニメーション数
	DrawRotaGraph(pos.x, pos.y, 1, 0, _images[(int)_state][(_animCnt / 3) % _animFlame[(int)_state]], true, _turnFlag);
}
