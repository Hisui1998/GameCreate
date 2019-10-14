#include "Player.h"

constexpr float speed = 3.0f;

void Player::Move()
{
	GetHitKeyStateAll(_key);

	if (_key[KEY_INPUT_UP])
	{
		pos.y -= speed;
	}
	if (_key[KEY_INPUT_DOWN])
	{
		pos.y += speed;
	}
	if (_key[KEY_INPUT_LEFT])
	{
		pos.x -= speed;
	}
	if (_key[KEY_INPUT_RIGHT])
	{
		pos.x += speed;
	}
}

Player::Player()
{
}


Player::~Player()
{
}

bool Player::Init()
{
	return false;
}

void Player::UpDate(char* key)
{
	_key = key;
	Move();
}

void Player::Draw()
{
	DrawCircle(pos.x,pos.y,2,0xffffff);
}
