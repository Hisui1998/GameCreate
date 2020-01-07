#pragma once
#include "Actor.h"
#include <string>
#include <vector>
#include <map>
#include <memory>

//---------------------------------------
//�R�[�h�@�L��
//���\�[�X�}�l�[�W���[�i�V���O���g���j
//�E�摜�̕`��@�E�A�j���[�V����
//---------------------------------------

//�ꖇ��̕`��p�}�N��
#define IMAGE_ID(X) (ResourceMng::Get()->GetID(X))

//�O���錾
class Actor;
class Player;


class ResourceMng
{
private:
	//�R���X�g���N�^
	ResourceMng();
	ResourceMng(const ResourceMng&) = delete;
	void operator=(const ResourceMng&) = delete;

	//�`�悷��摜�̃t�@�C��������������A�z�z��N���X
	std::map<std::string, std::vector<int>> _rscMap;
	//�t�@�C����
	std::string _fileName;

	static std::unique_ptr<ResourceMng> _instance;

public:
	//�f�X�g���N�^
	~ResourceMng();
	static std::unique_ptr<ResourceMng> &Get(void)
	{
		return _instance;
	}

	//�ꖇ��̃��\�[�X�p
	const std::vector<int> GetID(const std::string fileName);
	//�A�j���[�V�����摜�p
	const std::vector<int> GetID(const std::string fileName, Vec2 divSize, Vec2 divCnt);
};

