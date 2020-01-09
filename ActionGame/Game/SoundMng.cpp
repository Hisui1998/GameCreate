#include "SoundMng.h"

std::unique_ptr<SoundMng> SoundMng::_instance(new SoundMng());

//コンストラクタ
SoundMng::SoundMng()
{
}

//デストラクタ
SoundMng::~SoundMng()
{
}

//サウンドファイル検索と読み込み用
const std::vector<int> SoundMng::GetSound(std::string soundName)
{
	if (_soundMap.find(soundName) == _soundMap.end())
	{
		//_soundMap[soundName].resize(1);
		LoadSoundMem(soundName.c_str());
	}

	return _soundMap[soundName];
}

//サウンドのセット
const std::vector<int> SoundMng::SetSound(std::string soundName, SOUND_TYPE type)
{
	return std::vector<int>();
}
