#include "GameMain.h"



GameMain::GameMain()
{
	if (init()) std::cout << "ƒQ[ƒ€ƒV[ƒ“‰Šú‰»Š®—¹" << std::endl;
	else std::cout << "ƒQ[ƒ€ƒV[ƒ“‰Šú‰»¸”s" << std::endl;
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
