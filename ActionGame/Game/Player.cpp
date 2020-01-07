#include "Player.h"
#include "ResourceMng.h"
#include "Scene.h"

constexpr float speed = 3.0f;

//�v���C���[�ړ�
// idleFlag ��~�����邩�����Ȃ���
int Player::StateMove(void)
{
	if (CheckHitKey(_config->GetKey("Up")))			//�W�����v
	{
		pos.y -= speed;
	}
	if (CheckHitKey(_config->GetKey("Down")))		//���Ⴊ��
	{
		pos.y += speed;
	}
	if (CheckHitKey(_config->GetKey("Left")))		//���ړ�
	{
		idleFlag = false;
		pos.x -= speed;
	}
	else if (CheckHitKey(_config->GetKey("Right")))	//�E�ړ�
	{
		idleFlag = false;
		pos.x += speed;
	}
	else
	{
		idleFlag = true;							//��~��Ԃ�
	}

	if (CheckHitKey(_config->GetKey("Attack")))		//�U��
	{
	}

	return 0;
}

//�W�����v����������
int Player::StateJump(void)
{
	return 0;
}

//����
int Player::StateFall(void)
{
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
	//���\�[�X������
	_images[0] = ResourceMng::Get()->GetID("../Resource/Player/player.png", { 80, 96 }, { 10, 2 });	//�ʏ�
	_images[1] = ResourceMng::Get()->GetID("../Resource/Player/walk.png", { 80, 96 }, { 10, 2 });	//����
	_animCnt = 0;

	//�K���ȃv���C�C���[�̈ʒu
	pos = { 40, 500 };
	idleFlag = false;

	//�֐��|�C���^
	_state = ANIM_STATE::MOVE;
	stateTbl[static_cast<int>(ANIM_STATE::MOVE)] = &Player::StateMove;
	stateTbl[static_cast<int>(ANIM_STATE::FALL)] = &Player::StateFall;
	stateTbl[static_cast<int>(ANIM_STATE::SHORT_RANGE_ATK)] = &Player::StateAttack;
	stateTbl[static_cast<int>(ANIM_STATE::RANGE_ATK)] = &Player::StateShot;

	_config = std::make_shared<Config>();

	return false;
}

//�X�V
void Player::UpDate(char* key)
{
	_key = key;
	(this->*stateTbl[static_cast<int>(_state)])();
}

//�v���C���[�`��
void Player::Draw()
{
	//_images�z��̒��́i(_animCnt++/�t���[����)%�`�悵�����A�j���[�V������

	if (CheckHitKey(_config->GetKey("Right")))		//�E�����A�j���[�V����
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, false);
	}
	else if (CheckHitKey(_config->GetKey("Left")))	//�������A�j���[�V����
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[1][(_animCnt++ / 5) % 10], true, true);
	}

	if (idleFlag == true)							//��~�A�j���[�V����
	{
		DrawRotaGraph(pos.x, pos.y, 1, 0, _images[0][(_animCnt++ / 5) % 12], true);
	}
}