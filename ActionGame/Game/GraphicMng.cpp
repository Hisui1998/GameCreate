#include "GraphicMng.h"

std::unique_ptr<GraphicMng> GraphicMng::_instance(new GraphicMng());


//�R���X�g���N�^
GraphicMng::GraphicMng()
{
	pos = { 0,0 };
}
//�f�X�g���N�^
GraphicMng::~GraphicMng()
{
}


bool GraphicMng::Init(std::string fileName, Vec2 divSize, Vec2 divCnt, Vec2 offset, int animCnt)
{
	GetID(fileName, divSize, divCnt, offset);
	this->fileName = fileName;
	this->divSize = divSize;
	this->offset = offset;
	this->_animCnt = animCnt;
	
	return false;
}

const VEC_INT& GraphicMng::GetID(std::string fileName)
{
	if (_graphicMap.find(fileName) == _graphicMap.end())
	{
		//�摜ID�̓ǂݍ��݂ƃn���h���쐬
		_graphicMap[fileName].resize(1);
		_graphicMap[fileName][0] = LoadGraph(fileName.c_str());
	}
	return _graphicMap[fileName];		//�摜ID�������
}

const VEC_INT& GraphicMng::GetID(std::string fileName, Vec2 divSize, Vec2 divCnt, Vec2 offset)
{
	if (_graphicMap.find(fileName) == _graphicMap.end())
	{
		//�摜ID�̓ǂݍ��݂ƃn���h���쐬
		_graphicMap[fileName].resize(divCnt.x * divCnt.y);
		LoadDivGraph(fileName.c_str(), divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &_graphicMap[fileName][0], true);
	}

	return _graphicMap[fileName];	//�摜ID�������
}


void GraphicMng::Draw(Vec2 &pos)
{
	if (fileName.length() == 0)
	{
		return;
	}

	DrawGraph(pos.x, pos.y, IMAGE_ID(fileName)[offset.x + divCnt.x * offset.y], true);
}

//�A�j���[�V�����p
void GraphicMng::Draw(int id)
{
	if (fileName.length() == 0)
	{
		return;
	}

	int num = 0;

	/*if (_animMap.find(_animName) != _animMap.end())
	{
		num = _animMap[_animName][ANIM_ID] + (_animCnt / _animMap[_animName][ANIM_WAIT_CNT]) % _animMap[_animName][ANIM_FLAME];
	}*/

	DrawGraph(pos.x, pos.y, IMAGE_ID(fileName)[id], true);
}