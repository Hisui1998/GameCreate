#include "GameTitle.h"
#include "GameMain.h"
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
	for (int i = 0; i < 256; ++i){
		_oldKey[i] = 0;
	}
	return true;
}

std::unique_ptr<Scene> GameTitle::UpDate(std::unique_ptr<Scene> &_this, char key[256])
{
	_flame++;
	// �������u�Ԃ����m���郉���_��
	auto CheckKeyTrigger = [key = key, _oldKey = _oldKey](int checkInputKey)->bool {
		return (key[checkInputKey] && (_oldKey[checkInputKey] == 0));
	};

	if (CheckKeyTrigger(KEY_INPUT_UP)) {
		_nowSelect--;
	}
	else if (CheckKeyTrigger(KEY_INPUT_DOWN)) {
		_nowSelect++;
	}

	// �X�y�[�X�L�[�����őI�𒆂̃V�[���֑J��
	if (CheckKeyTrigger(KEY_INPUT_SPACE)){
		switch ((NextScene)(abs(_nowSelect%(int)NextScene::Max)))
		{
		case NextScene::Main:
			return std::make_unique<GameMain>();
			break;
		case NextScene::Config:
			// �R���t�B�O�̃V�[����
			//return std::make_unique<Config>();
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
	// �e�X�g�p---------------------------------//
	DrawString(0, 0, "TitleScene", 0xffffff);
	if (_flame/20%2){
		DrawString(0, 15 + abs(_nowSelect % (int)NextScene::Max) * 15, ">>", 0xffffff);
	}
	DrawString(20, 15, "GameMain", 0xffffff);
	DrawString(20, 30, "Config", 0xffffff);
	DrawString(20, 45, "End", 0xffffff);
	//------------------------------------------//
}
