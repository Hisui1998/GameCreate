#pragma once
#include "PrtAttack.h"
class Shot :
	public PrtAttack
{
public:
	//actor‚Ìpos,size,dir,shot‚Ì‰æ‘œsize
	Shot(Vec2 pos, Vec2 size, Vec2 dir, Vec2 atkSize);
	~Shot();

	bool Init(void) override;
	void UpDate(char* key) override;
	void Draw(void)override;
};

