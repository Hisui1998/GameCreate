#include "GameMain.h"
#include "GameTitle.h"
#include "Player.h"

GameMain::GameMain()
{
	if (init()) std::cout << "ゲームシーン初期化完了" << std::endl;
	else std::cout << "ゲームシーン初期化失敗" << std::endl;
}


GameMain::~GameMain()
{
}

bool GameMain::init()
{
	_player = std::make_unique<Player>();
	return true;
}

std::unique_ptr<Scene> GameMain::UpDate(std::unique_ptr<Scene> &_this, char key[256])
{
	_flame++;
	_player->UpDate(key);
	_player->Draw();

	return std::move(_this);
}

void GameMain::Draw()
{
	DrawString(0, 0, "MainScene", 0xffffff);
}
