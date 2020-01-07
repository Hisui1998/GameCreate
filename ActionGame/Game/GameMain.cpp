#include "GameMain.h"
#include "GameTitle.h"
#include "Player.h"

GameMain::GameMain()
{
	if (Init()) std::cout << "�Q�[���V�[������������" << std::endl;
	else std::cout << "�Q�[���V�[�����������s" << std::endl;
}


GameMain::~GameMain()
{
}

bool GameMain::Init()
{
	_bgImage.emplace_back(LoadGraph("../Resource/BackGround/�w�i���̂�.png"));
	_bgImage.emplace_back(LoadGraph("../Resource/BackGround/�w�i�R�̂�.png"));
	_bgImage.emplace_back(LoadGraph("../Resource/BackGround/�w�i���̂�.png"));
	_player = std::make_unique<Player>();
	lpMapCtl->RoadMap("mapdata-1");
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
	for (auto& bg:_bgImage)
	{
		DrawExtendGraph(0, 0, 1440,600,bg,true);
	}
	DrawString(0, 0, "MainScene", 0xffffff);
}
