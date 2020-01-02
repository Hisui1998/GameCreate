#pragma once
#include "Actor.h"

class PrtAttack :
	public Actor
{
protected:
	Vec2 pos;
	Vec2 dir;
	float speed;
	Vec2 size;

	bool alive;

public:
	PrtAttack();
	virtual ~PrtAttack();

	virtual bool Init() = 0;
	virtual void UpDate(char* key) = 0;
	virtual void Draw() = 0;

	//Getä÷êî
	Vec2 GetPos() { return pos; };
	Vec2 GetDir() { return dir; };
	Vec2 GetSize() { return size; };

	bool isAlive() { return alive; };

	void CallDeath(void);
	void DestroyProc(void);
};

