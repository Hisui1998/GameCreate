#include "GameTitle.h"
#include "GameMain.h"
#include "Config.h"
#include "Application.h"
#include "Player.h"


GameTitle::GameTitle()
{
	if (Init()) std::cout << "タイトルシーン初期化完了" << std::endl;
	else std::cout << "タイトルシーン初期化失敗" << std::endl;
}

GameTitle::~GameTitle()
{
}

bool GameTitle::Init()
{
	for (int i = 0; i < 256; ++i){
		_oldKey[i] = 0;
	}
	return true;
}

std::unique_ptr<Scene> GameTitle::Update(std::unique_ptr<Scene> &_this, char key[256])
{
	if (CheckKeyTrigger(key,_keyState["Up"])) {
		_nowSelect--;
	}
	else if (CheckKeyTrigger(key,_keyState["Down"])) {
		_nowSelect++;
	}

	// スペースキー押下で選択中のシーンへ遷移
	if (CheckKeyTrigger(key,_keyState["Attack"])){
		switch ((NextScene)(abs(_nowSelect%(int)NextScene::Max)))
		{
		case NextScene::Main:
			return std::make_unique<GameMain>();
			break;
		case NextScene::Config:
			// コンフィグのシーンを追加
			Application::Instance()->AddScene(std::make_unique<Config>());
			break;
		case NextScene::End:
		default:
			return nullptr;
			break;
		}
	}

	for (int i = 0; i < 256; ++i){
		_oldKey[i] = key[i];
	}
	return std::move(_this);
}

void GameTitle::Draw()
{
	_drawFlame++;
	// テスト用---------------------------------//
	DrawString(0, 0, "TitleScene", 0xffffff);
	if (_drawFlame/20%2){
		DrawString(0, 15 + abs(_nowSelect % (int)NextScene::Max) * 15, ">>", 0xffffff);
	}
	DrawString(20, 15, "GameMain", 0xffffff);
	DrawString(20, 30, "Config", 0xffffff);
	DrawString(20, 45, "End", 0xffffff);
	//------------------------------------------//
}
