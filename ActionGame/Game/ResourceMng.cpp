#include "ResourceMng.h"

std::unique_ptr<ResourceMng> ResourceMng::_instance(new ResourceMng());


//�R���X�g���N�^
ResourceMng::ResourceMng()
{
}
//�f�X�g���N�^
ResourceMng::~ResourceMng()
{
}


//�ꖇ��̃��\�[�X�p
//���\�[�XID�̓ǂݍ��݂ƃn���h���쐬
const std::vector<int> ResourceMng::GetID(std::string fileName)
{
	//�t�@�C��������
	if (_rscMap.find(fileName) == _rscMap.end())
	{
		_rscMap[fileName].resize(1);
		_rscMap[fileName][0] = LoadGraph(fileName.c_str());
	}

	//�쐬�����n���h����Ԃ�
	return _rscMap[fileName];		
}

//�A�j���[�V�����`��p
//���\�[�XID�̓ǂݍ��݂ƃn���h���쐬
//divSize : �����������摜�̃T�C�Y,�@divCnt : �摜�̕�����
const std::vector<int> ResourceMng::GetID(std::string fileName, Vec2 divSize, Vec2 divCnt)
{
	//�t�@�C��������
	if (_rscMap.find(fileName) == _rscMap.end())
	{
		_rscMap[fileName].resize(divCnt.x * divCnt.y);
		LoadDivGraph(fileName.c_str(),divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &_rscMap[fileName][0], true);
	}

	//�쐬�����n���h����Ԃ�
	return _rscMap[fileName];
}