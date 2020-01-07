#include "Proximity.h"

Proximity::Proximity(Vec2 pos, Vec2 size, Vec2 dir, Vec2 atkSize, int flameMax)
{
	this->size = atkSize;
	this->dir = Vec2(0, 1);
	speed = size.y / flameMax;
	if (dir.x >= 0)
	{
		this->pos = Vec2(pos.x + size.x, pos.y - speed);
	}
	else
	{
		this->pos = Vec2(pos.x - atkSize.x, pos.y - speed);
	}
	alive = true;
}

Proximity::~Proximity()
{
}

bool Proximity::Init(void)
{
	return false;
}

void Proximity::UpDate(char* key)
{
	pos.y += dir.y * speed;
}

void Proximity::Draw(void)
{
	DrawBox(pos.x, pos.y, pos.x + size.x, pos.y + size.y, 0xffff00, false);
}