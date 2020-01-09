#pragma once
#include <memory>
#include <map>
#include <string>
#include <vector>
#include <DxLib.h>

//------------------------------------
//音楽マネージャー (シングルトン）
//音楽ファイルの検索　バックグラウンド再生かループ再生の選択
//------------------------------------

//再生するサウンドのタイプ
enum SOUND_TYPE
{
	back = DX_PLAYTYPE_BACK,	//バックグラウンド再生
	loop = DX_PLAYTYPE_LOOP		//ループ再生
};

class SoundMng
{
private:
	//コンストラクタ
	SoundMng();
	SoundMng(const SoundMng&) = delete;
	void operator=(const SoundMng&) = delete;

	static std::unique_ptr<SoundMng> _instance;

	//サウンドファイル検索用
	std::map<std::string, std::vector<int>> _soundMap;
	//サウンドファイル名
	std::string _soundName;

public:
	//デストラクタ
	~SoundMng();
	static std::unique_ptr<SoundMng> &Get(void)
	{
		return _instance;
	}

	//サウンドファイルの検索
	const std::vector<int> GetSound(std::string soundName);
	const std::vector<int> SetSound(std::string soundName, SOUND_TYPE type);
};

