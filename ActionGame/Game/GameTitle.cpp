#include "GameTitle.h"
#include "Player.h"


GameTitle::GameTitle()
{
	if (init()) std::cout << "�^�C�g���V�[������������" << std::endl;
	else std::cout << "�^�C�g���V�[�����������s" << std::endl;
}

GameTitle::~GameTitle()
{
}

bool GameTitle::init()
{
	return true;
}

SCENE GameTitle::UpDate(SCENE &_this)
{
	mouseBtn[ST_OLD] = mouseBtn[ST_NOW];
	mouseBtn[ST_NOW] = GetMouseInput();

	if ((mouseBtn[ST_NOW]) & (~mouseBtn[ST_OLD]) & MOUSE_INPUT_LEFT)
	{
		return std::make_unique<GameMain>();
	}

	return std::move(_this);

}

void GameTitle::Draw()
{
	DrawString(0, 0, "GameTitle", 0xffffff);
}
