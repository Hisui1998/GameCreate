#include "Player.h"
#include "ResourceMng.h"
#include "Scene.h"

constexpr float speed = 3.0f;

//�v���C���[�ړ�
// _idleFlag ��~�����邩�����Ȃ���
int Player::StateMove(void)
{
	_idleFlag = false;
	_isJump = false;

	if (CheckHitKey(_config->GetKey("Up")))				//�W�����v�֑J��
	{
		_state = ANIM_STATE::JUMP;
	}
	else if (CheckHitKey(_config->GetKey("Down")))		//���Ⴊ��
	{
	}
	else if (CheckHitKey(_config->GetKey("Right")))		//�E�ړ�
	{
		_turnFlag = true;
		pos.x += speed;
	}
	else if (CheckHitKey(_config->GetKey("Left")))		//���ړ�
	{
		 _turnFlag = false;
		pos.x -= speed;
	}
	else
	{
		_idleFlag  = true;								//��~���
	}

	return 0;
}

//�W�����v����
int Player::StateJump(void)
{
	//�W�����v���Ă��邩
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

	//�W�����v
	if (CheckHitKey(_config->GetKey("Up")) && _isJump == false)
	{
		_isJump = true;
		prev.y = pos.y;
		pos.y = pos.y - 15;
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
	//���ꂼ��̃��\�[�X�j��
	//for (int i = 0; i < 3; ++i)
	//{
	//	for (auto& image : _images[i])
	//	{
	//		DeleteGraph(image, true);
	//	}
	//}
}

//������
bool Player::Init()
{
	//���\�[�X������	
	_images[0] = ResourceMng::Get()->GetID("../Resource/Player/player.png", { 80, 96 }, { 10, 2 });	//�ʏ�
	_images[1] = ResourceMng::Get()->GetID("../Resource/Player/walk.png", { 80, 96 }, { 10, 2 });	//����
	_images[2] = ResourceMng::Get()->GetID("../Resource/Player/jump2.png", { 80, 96 }, { 10, 2 });	//�W�����v
	_image = ResourceMng::Get()->GetID("../Resource/Player/squat.png");								//���Ⴊ��

	_animCnt = 0;

	pos = { 40, 400 };
	//�W�����v����Ƃ���pos�i�[�p
	temp = { 0,0 };
	prev = { 0,0 };

	_turnFlag = false;
	_idleFlag = false;
	_isJump = false;

	//�֐��|�C���^������
	_state = ANIM_STATE::MOVE;
	stateTbl[static_cast<int>(ANIM_STATE::MOVE)]			= &Player::StateMove;
	stateTbl[static_cast<int>(ANIM_STATE::JUMP)]			= &Player::StateJump;
	stateTbl[static_cast<int>(ANIM_STATE::FALL)]			= &Player::StateFall;
	stateTbl[static_cast<int>(ANIM_STATE::SHORT_RANGE_ATK)] = &Player::StateAttack;
	stateTbl[static_cast<int>(ANIM_STATE::RANGE_ATK)]		= &Player::StateShot;

	//�R���t�B�O
	_config = std::make_shared<Config>();

	return false;
}

//�X�V
void Player::UpDate(char* key)
{
	(this->*stateTbl[static_cast<int>(_state)])();	
}

//�v���C���[�`��
void Player::Draw()
{
	//_images�z��̒��́i(_animCnt++/�t���[����)%�`�悵�����A�j���[�V������

	//�W�����v�A�j���[�V����
	if (_isJump)												
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[2][(_animCnt++ / 3) % 13], true, false);
	}

	//���Ⴊ��
	else if (CheckHitKey(_config->GetKey("Down")))					
	{
		for (auto& image : _image)
		{
			DrawRotaGraph(pos.x, pos.y, 1, 0, image, true, false);
		}
	}

	//�E�����A�j���[�V����
	else if (CheckHitKey(_config->GetKey("Right")) && _turnFlag)
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, false);		
	}

	//�������A�j���[�V����
	else if (CheckHitKey(_config->GetKey("Left")) && !_turnFlag)
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, true);
	}
	
	//��~�A�j���[�V����
	else if (!CheckHitKeyAll() || _idleFlag)
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[0][(_animCnt++ / 5) % 12], true);
	}
}
