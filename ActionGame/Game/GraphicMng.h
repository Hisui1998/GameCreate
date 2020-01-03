#pragma once
#include "Actor.h"
#include "Single.h"
#include <string>
#include <vector>
#include <map>
#include <memory>

//---------------------------------------
//�R�[�h�@�L��
//�O���t�B�b�N�}�l�[�W���[(�V���O���g���j
//---------------------------------------



//�A�j���[�V�����AID�A�R�}���A�A�j���[�V�����Ԋu
enum ANIM_STATUS
{
	ANIM_ID,
	ANIM_FLAME,
	ANIM_WAIT_CNT,
	ANIM_MAX
};

#define IMAGE_ID(X) (GraphicMng::Get()->GetID(X))
using VEC_INT = std::vector<int>;

//�O���錾
class Actor;
class Player;

class GraphicMng
{
private:
	//�R���X�g���N�^
	GraphicMng();
	GraphicMng(const GraphicMng&) = delete;
	void operator=(const GraphicMng&) = delete;

	Vec2 pos;
	Vec2 divCnt;
	Vec2 divSize;
	Vec2 offset;
	int _animCnt;

	//�t�@�C����
	std::string fileName;

	//�摜�p�}�b�v
	std::map<std::string, VEC_INT> _graphicMap;

	//�A�j���[�V�����p�}�b�v
	std::map<std::string, int[ANIM_MAX]> _animMap;
	std::string _animName;

	static std::unique_ptr<GraphicMng> _instance;

public:
	//�f�X�g���N�^
	~GraphicMng();
	static std::unique_ptr<GraphicMng>& Get(void)
	{
		return _instance;
	}

	//������
	bool Init(std::string fileName, Vec2 divSize, Vec2 divCnt, Vec2 offset, int animCnt);

	//�`��p
	const VEC_INT& GetID(const std::string fileName);
	const VEC_INT& GetID(const std::string fileName, Vec2 divSize, Vec2 divCnt, Vec2 offset);

	//�`��p
	void Draw(Vec2 &pos);
	//�A�j���[�V�����p
	void Draw(int id);
	
};

