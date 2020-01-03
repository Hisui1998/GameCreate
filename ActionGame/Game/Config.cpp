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
	/// _isChange�t���O�������Ă�����L�[�ύX�̃A�b�v�f�[�g�ֈڍs
	if (_isChange)
	{
		ChangeKeyUpdate(key);
	}
	/// �U���L�[�������ꂽ�ꍇ�L�[�ύX��Ԃֈڍs
	else if (CheckKeyTrigger(key,_keyState["Attack"]))
	{
		_isChange = true;
		_changeKeyNum = 0;
	}
	/// ESC�L�[�������ꂽ�ꍇ��NullPtr��Ԃ��ă|�[�Y��ʂ��I������
	else if (CheckKeyTrigger(key,KEY_INPUT_ESCAPE))
	{
		return nullptr;
	}
	
	/// �O�t���[���̃L�[���Ƃ��Ċi�[
	for (int i = 0; i < 256; ++i) {
		_oldKey[i] = key[i];
	}
	return std::move(_this);
}

// �L�[�̔z�u�ύX�������s���֐�
void Config::ChangeKeyUpdate(const char key[256])
{
	for (int i = 0; i < 256; ++i)
	{
		// �{�^���������ꂽ�u�ԉ����ꂽ�L�[�ɕύX���A���������Ȃ�_changeKeyNum�����Z����
		if ((CheckKeyTrigger(key,i)) && (ChangeKeyState(KeyName[_changeKeyNum], i)))
		{
			if (++_changeKeyNum >= KeyName.size())
			{
				_isChange = false;
				_changeKeyNum = 0;
			}
		}
	}
}

// �L�[���̕ύX
// stateName::����������L�[�̖��O
// keyValue::�L�[�ԍ�
// �ύX������True�A�ύX���Ȃ������Ƃ���False��Ԃ�
bool Config::ChangeKeyState(const std::string& stateName,const int& keyValue)
{
	// �����ł�����Ă������̃`�F�b�N
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
		DrawFormatString(120, 40+20* _changeKeyNum, 0xffffff, "�ύX��");
	}
	if (_isChange)
	{
		DrawString(150, 20, "�L�[���", 0xffffff);
		DrawFormatString(180, 40, 0xffffff, "Up->%d", _keyState["Up"]);
		DrawFormatString(180, 60, 0xffffff, "Down->%d", _keyState["Down"]);
		DrawFormatString(180, 80, 0xffffff, "Left->%d", _keyState["Left"]);
		DrawFormatString(180, 100, 0xffffff, "Right->%d", _keyState["Right"]);
		DrawFormatString(180, 120, 0xffffff, "Attack->%d", _keyState["Attack"]);
	}
	else
	{
		DrawString(150, 20, "�U���{�^���ŃL�[�z�u�ύX\nESC�L�[�Ń^�C�g���ɖ߂�", 0xffffff);
	}
}
