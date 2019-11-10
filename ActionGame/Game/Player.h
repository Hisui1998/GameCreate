#pragma once
#include "Actor.h"
class Player :
	public Actor
{
private:
	Vec2 pos;
	char* _key;
	void Move();
public:
	Player();
	~Player();

	bool Init();
	void UpDate(char* key);
	void Draw();

	Vec2 GetPos() { return pos; };
	void SetPos(Vec2 inpos) { pos = inpos; };
};

