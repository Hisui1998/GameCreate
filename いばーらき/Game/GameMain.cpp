#include "GameMain.h"
#include "Player.h"


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
	_player = std::make_unique<Player>();
	return true;
}

void GameMain::UpDate()
{
	char key[256];
	GetHitKeyStateAll(key);
	_player->UpDate(key);
	_player->Draw();
}
