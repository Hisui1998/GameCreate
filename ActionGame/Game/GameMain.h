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
	std::unique_ptr<Scene> UpDate(std::unique_ptr<Scene> &_this, char key[256]);
	void Draw();
};

