#include "GameMain.h"
#include "GameTitle.h"
#include "Player.h"
/*
//�ύX�E�ǉ��_
:GameMain.h/cpp  :GameTitle.h/cpp :Application.h/cpp
*/

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

SCENE GameMain::UpDate(SCENE &_this)
{
	char key[256];
	GetHitKeyStateAll(key);
	_player->UpDate(key);
	_player->Draw();

	return std::move(_this);
}

void GameMain::Draw()
{
	DrawString(0, 0, "GameMain", 0xffffff);
}
