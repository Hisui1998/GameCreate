#include "GameMain.h"



GameMain::GameMain()
{
	if (init()) std::cout << "�Q�[���V�[������������" << std::endl;
	else std::cout << "�Q�[���V�[�����������s" << std::endl;
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
