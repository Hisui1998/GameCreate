#pragma once
#include "Actor.h"

//�U���̂��ƂɂȂ�N���X
class PrtAttack :
	public Actor
{
protected:
	Vec2 pos;		//�ʒu���
	Vec2 dir;		//�������
	float speed;	//���x
	Vec2 size;		//�A�N�^�[�̉摜�T�C�Y

	bool alive;		//�����t���O

public:
	PrtAttack();
	virtual ~PrtAttack();

	virtual bool Init() = 0;
	virtual void UpDate(char* key) = 0;
	virtual void Draw() = 0;

	//Get�֐�
	Vec2 GetPos() { return pos; };
	Vec2 GetDir() { return dir; };
	Vec2 GetSize() { return size; };

	//���̍U���������Ă��邩�ǂ���
	bool isAlive() { return alive; };

	//�U������������֐�
	void CallDeath(void);
	//�U�����폜���ꂽ���̂����肷��֐�
	void DestroyProc(void);
};

