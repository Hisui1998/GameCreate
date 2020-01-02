#include "Application.h"
#include "TestField.h"

std::shared_ptr<Application> Application::_appptr(new Application());

// 各種定数
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

Application::Application():wSize(WINDOW_WIDTH, WINDOW_HEIGHT)
{
	std::cout << "アプリケーションを開始します" << std::endl;
}


Application::~Application()
{
}

bool Application::Init()
{
	std::cout << "各種初期化を開始します" << std::endl;
	SetWindowTextA("ActionGame");
	SetGraphMode(wSize.width, wSize.height,32);
	SetDrawScreen(DX_SCREEN_BACK);
	ChangeWindowMode(true);
	if (DxLib_Init())
	{ 
		std::cout << "DxLib初期化失敗" << std::endl;
		return false;
	}
	else std::cout << "DxLib初期化完了" << std::endl;

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

		// 最新のシーンのデータのみ更新
		auto& nuwScene = _nowScenes.back();
		nuwScene = std::move(nuwScene->Update(nuwScene, key));

		// すべてのシーンの描画
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

