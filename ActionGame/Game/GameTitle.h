#pragma once
#include "Scene.h"
#include <map>

class Actor;

// タイトルシーンクラス
class GameTitle:
	public Scene
{
private:
	bool Init()override final;

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

	std::unique_ptr<Scene> Update(std::unique_ptr<Scene> &_this, char key[256])override final;
	void Draw()override final;
};

