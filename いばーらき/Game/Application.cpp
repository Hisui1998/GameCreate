#include "Application.h"
#include "GameMain.h"

std::shared_ptr<Application> Application::_appptr(new Application());

Application::Application():wSize()
{
	std::cout << "アプリケーションを開始します" << std::endl;
}


Application::~Application()
{
}

bool Application::Init()
{
	SetWindowTextA("Game");
	SetGraphMode(800,600,32);
	SetDrawScreen(DX_SCREEN_BACK);
	ChangeWindowMode(true);
	if (DxLib_Init())
	{ 
		std::cout << "DxLib初期化失敗" << std::endl;
		return false;
	}
	else std::cout << "DxLib初期化完了" << std::endl;

	NowScene = std::make_unique<GameMain>();

	return true;
}

int Application::Main()
{
	while (!ProcessMessage())
	{
		ClearDrawScreen();

		NowScene->UpDate();

		ScreenFlip();
	}
	return 0;
}

bool Application::End()
{
	DxLib_End();
	return true;
}