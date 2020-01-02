#pragma once
#include "PrtEnemy.h"

enum class StateID
{
	IDLE,		//��~��
	MOVE,		//�ړ�
	FALL,		//����
	PROXATK,	//�ߐڍU��
	SHOTATK,	//�������U��
	MAX
};

class Enemy :
	public PrtEnemy
{
private:
	//�֐��|�C���^
	int StateIdle(void);
	int StateMove(void);
	int StateFall(void);
	int StateProx(void);
	int StateShot(void);

	int (Enemy::*stateTbl[static_cast<int>(StateID::MAX)])(void);
	//�U�������ǂ���
	bool isAttack;
	//�U���̃A�j���[�V������
	int atkCount;

public:
	Enemy();
	//�ʒu���A�摜�T�C�Y
	Enemy(Vec2 pos, Vec2 size);
	~Enemy();

	//�I�[�o�[���C�h�֐��Q
	bool Init(void) override;
	void UpDate(char* key) override;
	void Draw(void)override;

	//�n�ʂƂ̔���A�ǂƂ̔���A�ύX���x,y
	void CheckBlock(bool isGround, bool isWall, const float& x, const float& y)override;

	StateID state;
};

