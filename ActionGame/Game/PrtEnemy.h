#pragma once
#include <vector>
#include <memory>
#include "Actor.h"

class PrtAttack;

class PrtEnemy :
	public Actor
{
protected:
	Vec2 pos;		//位置情報
	Vec2 dir;		//向き情報
	float speed;	//速度
	Vec2 size;		//アクターの画像サイズ

	bool alive;		//生存フラグ

	std::vector<std::shared_ptr<PrtAttack>> atkList;
public:
	PrtEnemy();
	virtual ~PrtEnemy();

	virtual bool Init() = 0;
	virtual void UpDate(char* key) = 0;
	virtual void Draw() = 0;
	virtual void CheckBlock(bool isGround, bool isWall, const float& x, const float& y) = 0;

	//Get関数
	Vec2 GetPos() { return pos; };
	Vec2 GetDir() { return dir; };
	Vec2 GetSize() { return size; };

};

