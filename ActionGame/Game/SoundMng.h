#pragma once
#include <memory>
#include <map>
#include <string>
#include <vector>
#include <DxLib.h>

//------------------------------------
//���y�}�l�[�W���[ (�V���O���g���j
//���y�t�@�C���̌����@�o�b�N�O���E���h�Đ������[�v�Đ��̑I��
//------------------------------------

//�Đ�����T�E���h�̃^�C�v
enum SOUND_TYPE
{
	back = DX_PLAYTYPE_BACK,	//�o�b�N�O���E���h�Đ�
	loop = DX_PLAYTYPE_LOOP		//���[�v�Đ�
};

class SoundMng
{
private:
	//�R���X�g���N�^
	SoundMng();
	SoundMng(const SoundMng&) = delete;
	void operator=(const SoundMng&) = delete;

	static std::unique_ptr<SoundMng> _instance;

	//�T�E���h�t�@�C�������p
	std::map<std::string, std::vector<int>> _soundMap;
	//�T�E���h�t�@�C����
	std::string _soundName;

public:
	//�f�X�g���N�^
	~SoundMng();
	static std::unique_ptr<SoundMng> &Get(void)
	{
		return _instance;
	}

	//�T�E���h�t�@�C���̌���
	const std::vector<int> GetSound(std::string soundName);
	const std::vector<int> SetSound(std::string soundName, SOUND_TYPE type);
};

