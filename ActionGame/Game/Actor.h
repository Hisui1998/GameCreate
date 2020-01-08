#pragma once
#include <DxLib.h>

struct Vec2 {
	float x;
	float y;
	Vec2() { x = 0, y = 0; };
	Vec2(float inx, float iny) { x = inx, y = iny; };


};

class Actor
{
protected:
	Vec2 pos;		//�ʒu���
	Vec2 dir;		//�������
	float speed;	//���x
	Vec2 size;		//�A�N�^�[�̉摜�T�C�Y

	bool alive;		//�����t���O

public:
	virtual ~Actor() {};
	virtual bool Init() = 0;
	virtual void UpDate(char* key) = 0;
	virtual void Draw() = 0;

	//Get�֐�
	Vec2 GetPos() { return pos; };
	Vec2 GetDir() { return dir; };
	Vec2 GetSize() { return size; };
};

