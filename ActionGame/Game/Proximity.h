#pragma once
#include "PrtAttack.h"

//‹ßÚUŒ‚—pƒNƒ‰ƒX
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

