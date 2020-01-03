#pragma once
#include "Scene.h"

class Actor;

// ゲームのメインシーンクラス
class GameMain :
	public Scene
{
private:
	bool Init()override final;
	std::unique_ptr<Actor> _player;
	std::unique_ptr<Actor> _enemy;

	// テスト用
	std::vector<int> _bgImage;
public:
	GameMain();
	~GameMain();
	std::unique_ptr<Scene> Update(std::unique_ptr<Scene> &_this, char key[256])override final;
	void Draw()override final;
};

