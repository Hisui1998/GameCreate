#include "Scene.h"

std::map<std::string, int> Scene::_keyState = {};


/// key:������s���L�[�z��
/// checkInputKey:������s���L�[�ԍ�
/// �����ꂽ�u�Ԃ̂�True��Ԃ��A����ȊO��False��Ԃ�
// �������u�Ԃ�Ԃ��֐�
bool Scene::CheckKeyTrigger(const char key[256], const int& checkInputKey)
{
	bool rtnFlag = false;
	// �S�p���{�ꃂ�[�h�̎������L�[�Ƃ��ȃL�[���������ςȂ��ɂȂ��Ă���̂ŏ��O
	if ((checkInputKey != KEY_INPUT_KANJI) && (checkInputKey != KEY_INPUT_KANA))
	{
		rtnFlag = (key[checkInputKey] && (_oldKey[checkInputKey] == 0));
	}

	return rtnFlag;
}

Scene::Scene() :KeyName({ "Up","Down", "Left", "Right","Attack" })
{
}

void Scene::PreAllInit()
{
	// �L�[�z�u�̏����ݒ�
	_keyState["Up"] = KEY_INPUT_UP;
	_keyState["Down"] = KEY_INPUT_DOWN;
	_keyState["Left"] = KEY_INPUT_LEFT;
	_keyState["Right"] = KEY_INPUT_RIGHT;
	_keyState["Attack"] = KEY_INPUT_SPACE;
}


