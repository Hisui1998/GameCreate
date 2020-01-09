#pragma once
#include "Actor.h"
#include "Player.h"
#include <vector>
#include <memory>


enum class ENEMY_STATE
{
	IDLE,				//�ʏ�
	MOVE,				//����
	SHORT_RANGE_ATK,	//�ߐڍU��
	LONG_RANGE_ATK,			//�������U��
	MAX
};


class TestEnemy :
	public Actor
{
private:
	//�֐��|�C���^�ł̏�ԑJ��
	int StateIdle(void);
	int StateMove(void);		//����
	int StateJump(void);		//�W�����v
	int StateAttack(void);		//�ߐڍU��
	int StateShot(void);		//�������U��

	int (TestEnemy::* stateTbl[static_cast<int>(ENEMY_STATE::MAX)])(void);

	ENEMY_STATE _state;

	Vec2 pos;			//���W
	RECT _hitBox;		// �������`
	RECT _attackBox;	// �������`
	int _animCnt;
	bool _deathFlag;

	std::vector<int> _images[(int)ENEMY_STATE::MAX];
	std::vector<int> _animFlame;

	std::shared_ptr<Actor> _player;

public:
	TestEnemy(std::shared_ptr<Actor> player);
	~TestEnemy();

	bool Init()override final;
	void UpDate(char* key)override final;
	void Draw()override final;

	void CheckHitBox(const RECT &rect, Vec2 pos);

	Vec2 GetPos() { return pos; };
	void SetPos(Vec2 inpos) { pos = inpos; }
};

