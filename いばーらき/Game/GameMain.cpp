#include "GameMain.h"



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
	idx = 0;
	return true;
}

void GameMain::UpDate()
{
	DrawCircle();
	idx++;
}
