#include "Player.h"
#include "ResourceMng.h"
#include "Scene.h"

constexpr float speed = 3.0f;

//�v���C���[�ړ�
// _idleFlag ��~�����邩�����Ȃ���
int Player::StateMove(void)
{
	
	if (CheckHitKey(_config->GetKey("Up")))				//�W�����v
	{
		if (!_isJump)
		{
			_isAerial = true;
			_state = ANIM_STATE::JUMP;
		}
		_isJump = true;
		
	}
	else if (CheckHitKey(_config->GetKey("Down")))		//���Ⴊ��
	{
		_idleFlag = false;
	}
	else if (CheckHitKey(_config->GetKey("Left")))		//���ړ�
	{
		_idleFlag = false;
		pos.x -= speed;
	}
	else if (CheckHitKey(_config->GetKey("Right")))		//�E�ړ�
	{
		_idleFlag = false;
		pos.x += speed;
	}
	else
	{
		_idleFlag  = true;								//��~��Ԃ�
	}

	if (CheckHitKey(_config->GetKey("Attack")))			//�U��
	{	
	}

	return 0;
}

//�W�����v����
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

//����
int Player::StateFall(void)
{
	pos.y += 0.3f;
	return 0;
}

//�ߐڍU��
int Player::StateAttack(void)
{
	return 0;
}

//�������U��
int Player::StateShot(void)
{
	return 0;
}

//�R���X�g���N�^
Player::Player()
{
	Init();
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
bool Player::Init()
{
	//OnInit(_vecx, _vecy);

	//���\�[�X������	
	_images[0] = ResourceMng::Get()->GetID("../Resource/Player/player.png", { 80, 96 }, { 10, 2 });	//�ʏ�
	_images[1] = ResourceMng::Get()->GetID("../Resource/Player/walk.png", { 80, 96 }, { 10, 2 });	//����
	_image = ResourceMng::Get()->GetID("../Resource/Player/squat.png");	

	_animCnt = 0;

	pos = { 40, 400 };
	//pos�i�[�p
	temp = { 0,0 };
	prev = { 0,0 };


	_idleFlag = false;
	_isJump = false;
	_isAerial = false;

	//�֐��|�C���^
	_state = ANIM_STATE::MOVE;
	stateTbl[static_cast<int>(ANIM_STATE::MOVE)] = &Player::StateMove;
	stateTbl[static_cast<int>(ANIM_STATE::JUMP)] = &Player::StateJump;
	stateTbl[static_cast<int>(ANIM_STATE::FALL)] = &Player::StateFall;
	stateTbl[static_cast<int>(ANIM_STATE::SHORT_RANGE_ATK)] = &Player::StateAttack;
	stateTbl[static_cast<int>(ANIM_STATE::RANGE_ATK)] = &Player::StateShot;

	//�R���t�B�O
	_config = std::make_shared<Config>();

	return false;
}

//�X�V
void Player::UpDate(char* key)
{
	(this->*stateTbl[static_cast<int>(_state)])();	

//	OnAccel(_vecx, _vecy);
//	OnMove(_vecx, _vecy);
}

//�v���C���[�`��
void Player::Draw()
{
	//_images�z��̒��́i(_animCnt++/�t���[����)%�`�悵�����A�j���[�V������

	if (CheckHitKey(_config->GetKey("Right")))		//�E�����A�j���[�V����
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, false);		
	}
	else if(CheckHitKey(_config->GetKey("Left")))	//�������A�j���[�V����
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
	

	if (_idleFlag == true)							//��~�A�j���[�V����
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
