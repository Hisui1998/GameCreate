#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Actor.h"


//MapChip�̎��
enum class ChipTypeB
{
	BLANK,
	WALL,
	GROUND,
	MAX
};

struct MapData
{
	Vec2 pos;
	ChipTypeB type;
};

#define lpMapCtl MapMng::Get()

//�O���錾
class Actor;

class MapMng
{
private:
	//�R���X�g���N�^
	MapMng();
	MapMng(const MapMng&) = delete;
	void operator=(const MapMng&) = delete;

	std::string convertPathFormatToUnixStyle(const std::string& path);

	//���̐���
	static std::unique_ptr<MapMng> _instance;

	//�ǂݍ��񂾃}�b�v���X�g�̃f�[�^
	std::vector<std::vector<MapData>> _mapData;

	//�����蔻����Ƃ����A�N�^�[�̈ʒu���������邽�߂̕ϐ�
	float posx, posy;

	//�}�b�v�`�b�v�ꖇ������̃T�C�Y
	int sizex, sizey;

	//�}�b�v�̑S�̂̃T�C�Y
	int fieldx, fieldy;

public:
	~MapMng();

	static std::unique_ptr<MapMng>& Get(void)
	{
		return _instance;
	}

	//�ǂݍ��ރ}�b�v�̖��O
	bool RoadMap(std::string mapName);

	//�t�B�[���h�Ƃ̓����蔻��p�֐�
	//�n�ʂƓ����蔻����Ƃ�A�N�^�[�ւ�shared_ptr, posy
	bool CheckGround(std::weak_ptr<Actor> actPtr, float& y);
	//�ǂƓ����蔻����Ƃ�A�N�^�[�ւ�shared_ptr, posx
	bool CheckWall(std::weak_ptr<Actor> actPtr, float& x);
};

