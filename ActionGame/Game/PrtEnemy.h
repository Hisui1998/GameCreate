#pragma once
#include <vector>
#include <memory>
#include "Actor.h"

class PrtAttack;

class PrtEnemy :
	public Actor
{
protected:
	Vec2 pos;		//�ʒu���
	Vec2 dir;		//�������
	float speed;	//���x
	Vec2 size;		//�A�N�^�[�̉摜�T�C�Y

	bool alive;		//�����t���O

	std::vector<std::shared_ptr<PrtAttack>> atkList;
public:
	PrtEnemy();
	virtual ~PrtEnemy();

	virtual bool Init() = 0;
	virtual void UpDate(char* key) = 0;
	virtual void Draw() = 0;
	virtual void CheckBlock(bool isGround, bool isWall, const float& x, const float& y) = 0;

	//Get�֐�
	Vec2 GetPos() { return pos; };
	Vec2 GetDir() { return dir; };
	Vec2 GetSize() { return size; };

};

