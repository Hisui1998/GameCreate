#include "GameTitle.h"
#include "GameMain.h"
#include "Config.h"
#include "Application.h"
#include "Player.h"


GameTitle::GameTitle()
{
	if (Init()) std::cout << "�^�C�g���V�[������������" << std::endl;
	else std::cout << "�^�C�g���V�[�����������s" << std::endl;
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

	// �X�y�[�X�L�[�����őI�𒆂̃V�[���֑J��
	if (CheckKeyTrigger(key,_keyState["Attack"])){
		switch ((NextScene)(abs(_nowSelect%(int)NextScene::Max)))
		{
		case NextScene::Main:
			return std::make_unique<GameMain>();
			break;
		case NextScene::Config:
			// �R���t�B�O�̃V�[����ǉ�
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
	// �e�X�g�p---------------------------------//
	DrawString(0, 0, "TitleScene", 0xffffff);
	if (_drawFlame/20%2){
		DrawString(0, 15 + abs(_nowSelect % (int)NextScene::Max) * 15, ">>", 0xffffff);
	}
	DrawString(20, 15, "GameMain", 0xffffff);
	DrawString(20, 30, "Config", 0xffffff);
	DrawString(20, 45, "End", 0xffffff);
	//------------------------------------------//
}
