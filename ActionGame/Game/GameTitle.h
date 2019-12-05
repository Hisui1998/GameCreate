#pragma once
#include "Scene.h"
#include <map>

class Actor;

class GameTitle:
	public Scene
{
private:
	bool init();

	// 次に移行するシーン
	enum class NextScene
	{
		Main,// メイン
		Config,// コンフィグ(オプション)
		End,// ゲーム終了
		Max// 最大数
	};

	int _nowSelect;// 選択中

	std::unique_ptr<Actor> _player;
public:
	GameTitle();
	~GameTitle();

	virtual std::unique_ptr<Scene> UpDate(std::unique_ptr<Scene> &_this, char key[256]);
	virtual void Draw();
};

