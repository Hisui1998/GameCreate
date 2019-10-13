#pragma once
#include "Scene.h"
class GameMain :
	public Scene
{
private:
	bool init();

	int idx;
public:
	GameMain();
	~GameMain();
	void UpDate();
};

