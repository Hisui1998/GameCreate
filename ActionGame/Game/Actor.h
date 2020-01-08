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
	Vec2 pos;		//位置情報
	Vec2 dir;		//向き情報
	float speed;	//速度
	Vec2 size;		//アクターの画像サイズ

	bool alive;		//生存フラグ

public:
	virtual ~Actor() {};
	virtual bool Init() = 0;
	virtual void UpDate(char* key) = 0;
	virtual void Draw() = 0;

	//Get関数
	Vec2 GetPos() { return pos; };
	Vec2 GetDir() { return dir; };
	Vec2 GetSize() { return size; };
};

