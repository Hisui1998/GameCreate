#pragma once
#include <DxLib.h>

class Actor
{
protected:
	struct Vec2 {
		float x;
		float y;
		Vec2() { x = 0, y = 0; };
		Vec2(float inx,float iny) { x = inx, y = iny; };

	};
public:
	virtual ~Actor() {};
	virtual bool Init() = 0;
	virtual void UpDate(char* key) = 0;
	virtual void Draw() = 0;
};

