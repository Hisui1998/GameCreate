#pragma once
#include "Actor.h"
#include "Config.h"
#include <memory>
#include <map>
#include <string>
#include <vector>

//----------------------------------------------
//�v���C���[�N���X
//----------------------------------------------

enum class ANIM_STATE
{
	MOVE,				//�ړ�
	JUMP,				//�W�����v
	FALL,				//����
	SHORT_RANGE_ATK,	//�ߐڍU��
	RANGE_ATK,			//�������U��
	MAX
};


class Player :
	public Actor
{
private:
	//�֐��|�C���^�ł̏�ԑJ��
	int StateMove(void);		//����
	int StateJump(void);		//�W�����v
	int StateFall(void);		//����
	int StateAttack(void);		//�ߐڍU��
	int StateShot(void);		//�������U��

	int (Player::* stateTbl[static_cast<int>(ANIM_STATE::MAX)])(void);

	//�v���C���[���W
	Vec2 pos;	
	char* _key;
	//��~�t���O
	bool idleFlag;
	//�A�j���[�V�����J�E���g
	int _animCnt;
	ANIM_STATE _state;

	//���\�[�X�i�[�p
	std::vector<int> _images[2];
	//�R���t�B�O
	std::shared_ptr<Config> _config;

public:
	Player();
	~Player();

	//������
	bool Init()override final;
	//�X�V
	void UpDate(char* key)override final;
	//�`��p
	void Draw()override final;

	Vec2 GetPos() { return pos; };
	void SetPos(Vec2 inpos) { pos = inpos; };
};

