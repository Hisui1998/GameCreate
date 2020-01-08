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

public:
	virtual ~Actor() {};
	virtual bool Init() = 0;
	virtual void UpDate(char* key) = 0;
	virtual void Draw() = 0;
};

