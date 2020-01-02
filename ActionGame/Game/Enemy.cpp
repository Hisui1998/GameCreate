#include "Enemy.h"
#include "Proximity.h"
#include "Shot.h"

Enemy::Enemy()
{
}

Enemy::Enemy(Vec2 pos, Vec2 size)
{
	this->pos = pos;
	this->size = size;
	Init();
}


Enemy::~Enemy()
{
}

bool Enemy::Init(void)
{
	dir = Vec2(1, 0);
	speed = 3.0f;
	atkCount = 0;
	state = StateID::FALL;
	isAttack = false;
	stateTbl[static_cast<int>(StateID::IDLE)] = &Enemy::StateIdle;
	stateTbl[static_cast<int>(StateID::MOVE)] = &Enemy::StateMove;
	stateTbl[static_cast<int>(StateID::FALL)] = &Enemy::StateFall;
	stateTbl[static_cast<int>(StateID::PROXATK)] = &Enemy::StateProx;
	stateTbl[static_cast<int>(StateID::SHOTATK)] = &Enemy::StateShot;
	return true;
}

void Enemy::UpDate(char * key)
{
	(this->*stateTbl[static_cast<int>(state)])();
	
	//Enemyの攻撃UpDate
	for (auto atkData : atkList)
	{
		atkData->UpDate(key);
	}


	//攻撃の自動削除処理
	auto itr = atkList.begin();
	while (itr != atkList.end())
	{
		if (!(*itr)->isAlive())
		{
			itr = atkList.erase(itr);
		}
		else
		{
			itr++;
		}
	}
}

void Enemy::Draw(void)
{
	DrawBox(pos.x, pos.y, pos.x + size.x, pos.y + size.y, 0xffff00,true);
	for (auto atkData : atkList)
	{
		atkData->Draw();
	}
}

void Enemy::CheckBlock(bool isGround, bool isWall, const float& x, const float& y)
{
	if (isGround)
	{
		pos.y = y;
		if (state == StateID::FALL)
		{
			state = StateID::IDLE;
		}
	}

	if (isWall)
	{
		pos.x = x;
		dir.x *= -1;
	}
}

int Enemy::StateIdle(void)
{
	state = StateID::SHOTATK;
	return 0;
}

int Enemy::StateMove(void)
{
	pos.x += dir.x * speed;
	pos.y += dir.y * speed;

	return 0;
}

int Enemy::StateFall(void)
{
	pos.y += 3;
	return 0;
}

int Enemy::StateProx(void)
{
	if (!isAttack)
	{
		isAttack = true;
		atkList.emplace_back(std::make_shared<Proximity>(pos,size,dir,Vec2(5, 5),4));
	}
	else
	{
		atkCount++;
	}

	//マジックナンバー4は攻撃アニメーションの最大フレーム数
	if (atkCount >= 4)
	{
		atkCount = 0;
		isAttack = false;
		atkList.front()->CallDeath();
		state = StateID::IDLE;
	}

	return 0;
}

int Enemy::StateShot(void)
{
	if (atkList.size() < 2)
	{
		atkList.emplace_back(std::make_shared<Shot>(pos, size, dir, Vec2(5, 5)));
	}

	state = StateID::IDLE;
	return 0;
}
