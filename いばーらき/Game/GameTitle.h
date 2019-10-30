#pragma once
#include "Scene.h"
#include "GameMain.h"
#include <memory>
#include <array>
/////////////////////////////////Žg‚¢ŽÌ‚Ä
enum STATE
{
	ST_NOW,
	ST_OLD,
	ST_MAX
};
using MOUSE_INT = std::array<int, ST_MAX>;

class Actor;

class GameTitle:
	public Scene
{
private:
	bool init();
	//std::unique_ptr<Scene> NowScene;
	std::unique_ptr<Actor> _player;
	///////////////
	MOUSE_INT mouseBtn;
	////////////////
public:
	GameTitle();
	~GameTitle();

	virtual SCENE UpDate(SCENE &_this);
	virtual void Draw();
};

