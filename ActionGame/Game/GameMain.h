#pragma once
#include "Scene.h"

class Actor;

class GameMain :
	public Scene
{
private:
	bool init();
	std::unique_ptr<Actor> _player;
public:
	GameMain();
	~GameMain();
	virtual SCENE UpDate(SCENE &_this);
	virtual void Draw();
};

