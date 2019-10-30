#include "Application.h"
#include "GameTitle.h"

std::shared_ptr<Application> Application::_appptr(new Application());

Application::Application():wSize()
{
	std::cout << "�A�v���P�[�V�������J�n���܂�" << std::endl;
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
		std::cout << "DxLib���������s" << std::endl;
		return false;
	}
	else std::cout << "DxLib����������" << std::endl;

	NowScene = std::make_unique<GameTitle>();

	return true;
}

int Application::Main()
{
	while (!ProcessMessage())
	{
		ClearDrawScreen();

		NowScene = std::move(NowScene->UpDate(NowScene));
		NowScene->Draw();

		ScreenFlip();
	}
	return 0;
}

bool Application::End()
{
	DxLib_End();
	return true;
}

