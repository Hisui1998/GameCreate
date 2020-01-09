#include "SoundMng.h"

std::unique_ptr<SoundMng> SoundMng::_instance(new SoundMng());

//�R���X�g���N�^
SoundMng::SoundMng()
{
}

//�f�X�g���N�^
SoundMng::~SoundMng()
{
}

//�T�E���h�t�@�C�������Ɠǂݍ��ݗp
const std::vector<int> SoundMng::GetSound(std::string soundName)
{
	if (_soundMap.find(soundName) == _soundMap.end())
	{
		//_soundMap[soundName].resize(1);
		LoadSoundMem(soundName.c_str());
	}

	return _soundMap[soundName];
}

//�T�E���h�̃Z�b�g
const std::vector<int> SoundMng::SetSound(std::string soundName, SOUND_TYPE type)
{
	return std::vector<int>();
}
