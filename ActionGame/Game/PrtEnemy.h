#pragma once
#include <vector>
#include <memory>
#include "Actor.h"

class PrtAttack;

class PrtEnemy :
	public Actor
{
protected:
	Vec2 pos;
	Vec2 dir;
	float speed;
	Vec2 size;

	std::vector<std::shared_ptr<PrtAttack>> atkList;
public:
	PrtEnemy();
	virtual ~PrtEnemy();

	virtual bool Init() = 0;
	virtual void UpDate(char* key) = 0;
	virtual void Draw() = 0;
	virtual void CheckBlock(bool,bool, const float&, const float&) = 0;

	//Getä÷êî
	Vec2 GetPos() { return pos; };
	Vec2 GetDir() { return dir; };
	Vec2 GetSize() { return size; };

};

