#include "GameMain.h"
#include "GameTitle.h"
#include "Player.h"

GameMain::GameMain()
{
	if (Init()) std::cout << "ƒQ[ƒ€ƒV[ƒ“‰Šú‰»Š®—¹" << std::endl;
	else std::cout << "ƒQ[ƒ€ƒV[ƒ“‰Šú‰»Ž¸”s" << std::endl;
}


GameMain::~GameMain()
{
}

bool GameMain::Init()
{
	_player = std::make_unique<Player>();
	return true;
}

std::unique_ptr<Scene> GameMain::Update(std::unique_ptr<Scene> &_this, char key[256])
{
	_player->UpDate(key);
	_player->Draw();

	return std::move(_this);
}

void GameMain::Draw()
{
	_drawFlame++;
	DrawString(0, 0, "MainScene", 0xffffff);
}
