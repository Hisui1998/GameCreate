#pragma once
#include "PrtAttack.h"

//�ߐڍU���p�N���X
class Proximity :
	public PrtAttack
{
public:
	//actor��pos,actor��size,actor��dir,�U������size,�U���t���[���̍ő吔
	Proximity(Vec2 pos, Vec2 size,Vec2 dir, Vec2 atkSize, int flameMax);
	~Proximity();

	bool Init(void) override;
	void UpDate(char* key) override;
	void Draw(void)override;
};

