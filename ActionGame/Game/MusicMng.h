#pragma once
#include <memory>

//------------------------------------
//音楽マネージャー (シングルトン）
//
//------------------------------------


class MusicMng
{
private:
	//コンストラクタ
	MusicMng();
	MusicMng(const MusicMng&) = delete;
	void operator=(const MusicMng&) = delete;

	static std::unique_ptr<MusicMng> _instance;

public:
	//デストラクタ
	~MusicMng();
	static std::unique_ptr<MusicMng> &GetID(void)
	{
		return _instance;
	}
};

