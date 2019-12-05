#include "Application.h"
#include "GameTitle.h"

std::shared_ptr<Application> Application::_appptr(new Application());

// �e��萔
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

Application::Application():wSize(WINDOW_WIDTH, WINDOW_HEIGHT)
{
	std::cout << "�A�v���P�[�V�������J�n���܂�" << std::endl;
}


Application::~Application()
{
}

bool Application::Init()
{
	std::cout << "�e�평�������J�n���܂�" << std::endl;
	SetWindowTextA("ActionGame");
	SetGraphMode(wSize.width, wSize.height,32);
	SetDrawScreen(DX_SCREEN_BACK);
	ChangeWindowMode(true);
	if (DxLib_Init())
	{ 
		std::cout << "DxLib���������s" << std::endl;
		return false;
	}
	else std::cout << "DxLib����������" << std::endl;

	_nowScene = std::make_unique<GameTitle>();

	return true;
}

int Application::Run()
{
	while (!ProcessMessage())
	{
		char key[256] = {};
		GetHitKeyStateAll(key);

		ClearDrawScreen();

		if ((_nowScene = std::move(_nowScene->UpDate(_nowScene, key))) == nullptr){
			return 1;
		}

		_nowScene->Draw();

		ScreenFlip();
	}
	return 0;
}

bool Application::End()
{
	DxLib_End();
	return true;
}

