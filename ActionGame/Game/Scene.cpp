#include "Scene.h"

std::map<std::string, int> Scene::_keyState = {};


// �������u�Ԃ�Ԃ��֐�
// key:������s���L�[�z��
// checkInputKey:������s���L�[�ԍ�
// �����ꂽ�u�Ԃ̂�True��Ԃ��A����ȊO��False��Ԃ�
bool Scene::CheckKeyTrigger(const char key[256], const int& checkInputKey)
{
	return (key[checkInputKey] && (_oldKey[checkInputKey] == 0));
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


