#include "Application.h"
#include "TestField.h"

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

	_nowScenes.emplace_back(std::make_unique<TestField>());
	_nowScenes.back()->PreAllInit();

	return true;
}

int Application::Run()
{
	while (!ProcessMessage())
	{
		char key[256] = {};
		GetHitKeyStateAll(key);

		ClearDrawScreen();

		// �ŐV�̃V�[���̃f�[�^�̂ݍX�V
		auto& nuwScene = _nowScenes.back();
		nuwScene = std::move(nuwScene->Update(nuwScene, key));

		// ���ׂẴV�[���̕`��
		for (auto& scene:_nowScenes){
			if (scene == nullptr)
			{
				_nowScenes.pop_back();
				continue;
			}
			scene->Draw();
		}

		ScreenFlip();
	}
	return 0;
}

bool Application::End()
{
	DxLib_End();
	return true;
}

void Application::AddScene(std::unique_ptr<Scene> inPtr)
{
	_nowScenes.emplace_back(std::move(inPtr));
}

