#include "Shot.h"

Shot::Shot(Vec2 pos, Vec2 size, Vec2 dir, Vec2 atkSize)
{
	this->size = atkSize;
	this->dir = dir;
	speed = 5;
	if (dir.x >= 0)
	{
		this->pos = Vec2(pos.x + size.x, pos.y + size.y / 2);
	}
	else
	{
		this->pos = Vec2(pos.x - atkSize.x, pos.y + size.y / 2);
	}
	alive = true;
}

Shot::~Shot()
{
}

bool Shot::Init(void)
{
	return false;
}

void Shot::UpDate(char* key)
{
	pos.x += dir.x * speed;

	if (pos.x <= 0 || pos.x >= 800)
	{
		alive = false;
	}
}

void Shot::Draw(void)
{
	DrawBox(pos.x, pos.y, pos.x + size.x, pos.y + size.y, 0xffff00, false);
}