#pragma once
#include <memory>

//------------------------------------
//���y�}�l�[�W���[ (�V���O���g���j
//
//------------------------------------


class MusicMng
{
private:
	//�R���X�g���N�^
	MusicMng();
	MusicMng(const MusicMng&) = delete;
	void operator=(const MusicMng&) = delete;

	static std::unique_ptr<MusicMng> _instance;

public:
	//�f�X�g���N�^
	~MusicMng();
	static std::unique_ptr<MusicMng> &GetID(void)
	{
		return _instance;
	}
};

