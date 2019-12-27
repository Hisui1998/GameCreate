#include "Config.h"



bool Config::Init()
{
	_isChange = false;
	_drawFlame = 0;
	return true;
}

Config::Config()
{
	Init();
}


Config::~Config()
{
}

std::unique_ptr<Scene> Config::Update(std::unique_ptr<Scene>& _this, char key[256])
{
	if (_isChange)
	{
		ChangeKeyUpdate(key);
	}
	else if (CheckKeyTrigger(key,_keyState["Attack"]))
	{
		_isChange = true;
		_changeKeyNum = 0;
	}
	else if (CheckKeyTrigger(key,KEY_INPUT_ESCAPE))
	{
		return nullptr;
	}
	

	for (int i = 0; i < 256; ++i) {
		_oldKey[i] = key[i];
	}
	return std::move(_this);
}

// キーの配置変更処理を行う関数
void Config::ChangeKeyUpdate(const char key[256])
{
	for (int i = 0; i < 256; ++i)
	{
		if (CheckKeyTrigger(key,i))
		{
			if (ChangeKeyState(KeyName[_changeKeyNum], i))
			{
				_changeKeyNum++;
			}
		}
	}
	if (_changeKeyNum >= KeyName.size())
	{
		_isChange = false;
	}
}

// キー情報の変更
// stateName::書き換えるキーの名前
// keyValue::キー番号
// 変更したらTrue、変更しなかったときはFalseを返す
bool Config::ChangeKeyState(const std::string& stateName,const int& keyValue)
{
	// 引数でもらってきた情報のチェック
	if (_keyState.find(stateName) != _keyState.end())
	{
		for (auto& checkkey : _keyState)
		{
			if ((checkkey.second == keyValue)&&(_keyState[stateName] != keyValue))
			{
				return false;
			}
		}
		_keyState[stateName] = keyValue;
		return true;
	}
	return false;
}

void Config::Draw()
{
	_drawFlame++;
	DrawString(150,0,"ConfigNow",0xffffff);
	if ((_isChange)&&((_drawFlame/20)%2))
	{
		DrawFormatString(120, 40+20* _changeKeyNum, 0xffffff, "変更中");
	}
	if (_isChange)
	{
		DrawString(150, 20, "キー情報", 0xffffff);
		DrawFormatString(180, 40, 0xffffff, "Up->%d", _keyState["Up"]);
		DrawFormatString(180, 60, 0xffffff, "Down->%d", _keyState["Down"]);
		DrawFormatString(180, 80, 0xffffff, "Left->%d", _keyState["Left"]);
		DrawFormatString(180, 100, 0xffffff, "Right->%d", _keyState["Right"]);
		DrawFormatString(180, 120, 0xffffff, "Attack->%d", _keyState["Attack"]);
	}
	else
	{
		DrawString(150, 20, "攻撃ボタンでキー配置変更", 0xffffff);
	}
}
