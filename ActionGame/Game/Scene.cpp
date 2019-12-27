#include "Scene.h"

std::map<std::string, int> Scene::_keyState = {};


// 押した瞬間を返す関数
// key:判定を行うキー配列
// checkInputKey:判定を行うキー番号
// 押された瞬間のみTrueを返し、それ以外はFalseを返す
bool Scene::CheckKeyTrigger(const char key[256], const int& checkInputKey)
{
	return (key[checkInputKey] && (_oldKey[checkInputKey] == 0));
}

Scene::Scene() :KeyName({ "Up","Down", "Left", "Right","Attack" })
{
}

void Scene::PreAllInit()
{
	// キー配置の初期設定
	_keyState["Up"] = KEY_INPUT_UP;
	_keyState["Down"] = KEY_INPUT_DOWN;
	_keyState["Left"] = KEY_INPUT_LEFT;
	_keyState["Right"] = KEY_INPUT_RIGHT;
	_keyState["Attack"] = KEY_INPUT_SPACE;
}


