#pragma once
#include "PrtAttack.h"

//近接攻撃用クラス
class Proximity :
	public PrtAttack
{
public:
	Proximity(Vec2 pos, Vec2 size,Vec2 dir, Vec2 atkSize, int flameMax);
	~Proximity();

	bool Init(void) override;
	void UpDate(char* key) override;
	void Draw(void)override;
};

