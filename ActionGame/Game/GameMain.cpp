#include "GameMain.h"
#include "GameTitle.h"
#include "Player.h"
#include "Enemy.h"
#include "ResourceMng.h"
#include "Application.h"

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
	_bgImage.emplace_back(IMAGE_ID("../Resource/BackGround/”wŒi¯‚Ì‚Ý.png"));
	_bgImage.emplace_back(IMAGE_ID("../Resource/BackGround/”wŒiŽR‚Ì‚Ý.png"));
	_bgImage.emplace_back(IMAGE_ID("../Resource/BackGround/”wŒiŒŽ‚Ì‚Ý.png"));
	_player = std::make_unique<Player>();
	_enemy = std::make_unique<Enemy>(Vec2(0, 100), Vec2(30, 30));
	return true;
}

std::unique_ptr<Scene> GameMain::Update(std::unique_ptr<Scene>& _this, char key[256])
{
	_player->UpDate(key);
	_enemy->UpDate(key);
	return std::move(_this);
}

void GameMain::Draw()
{
	_drawFlame++;
	for (auto& bg : _bgImage)
	{
		for (auto& image : bg)
		{
			DrawExtendGraph(0, 0, 1440, 600, image, true);
		}
	}
	_player->Draw();
	_enemy->Draw();
	DrawString(0, 0, "MainScene", 0xffffff);
	DrawLine(0, Application::Instance()->GetWindowSize().height - 50, Application::Instance()->GetWindowSize().width, Application::Instance()->GetWindowSize().height-50,0xffffff);
}