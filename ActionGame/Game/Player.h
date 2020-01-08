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

	ANIM_STATE _state;
	Vec2 pos;		//�v���C���[���W
	Vec2 _accel;		//������

	bool _idleFlag;	//��~�t���O
	bool _isAerial;
	bool _isJump;
	int _animCnt;	//�A�j���[�V�����J�E���g
	float _vecx, _vecy;

	//���\�[�X�i�[�p
	std::vector<int> _images[2];
	std::vector<int> _image;
	//�R���t�B�O
	std::shared_ptr<Config> _config;

public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	//������
	bool Init()override final;
	//�X�V
	void UpDate(char* key)override final;
	//�`��p
	void Draw()override final;

	void OnInit(float& vecx, float& vecy);
	void PushJump(float& vecx, float& vecy);
	void OnMove(float vecx, float vecy);
	void OnAccel(float& vecx, float& vecy);

	Vec2 GetPos() { return pos; };
	void SetPos(Vec2 inpos) { pos = inpos; };
};

