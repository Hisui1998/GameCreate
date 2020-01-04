#pragma once
#include "Actor.h"
#include "Single.h"
#include <string>
#include <vector>
#include <map>
#include <memory>

//---------------------------------------
//コード　有村
//グラフィックマネージャー(シングルトン）
//---------------------------------------



//アニメーション、ID、コマ数、アニメーション間隔
enum ANIM_STATUS
{
	ANIM_ID,
	ANIM_FLAME,
	ANIM_WAIT_CNT,
	ANIM_MAX
};

#define IMAGE_ID(X) (GraphicMng::Get()->GetID(X))
using VEC_INT = std::vector<int>;

//前方宣言
class Actor;
class Player;

class GraphicMng
{
private:
	//コンストラクタ
	GraphicMng();
	GraphicMng(const GraphicMng&) = delete;
	void operator=(const GraphicMng&) = delete;

	Vec2 pos;
	Vec2 divCnt;
	Vec2 divSize;
	Vec2 offset;
	int _animCnt;

	//ファイル名
	std::string fileName;

	//画像用マップ
	std::map<std::string, VEC_INT> _graphicMap;

	//アニメーション用マップ
	std::map<std::string, int[ANIM_MAX]> _animMap;
	std::string _animName;

	static std::unique_ptr<GraphicMng> _instance;

public:
	//デストラクタ
	~GraphicMng();
	static std::unique_ptr<GraphicMng>& Get(void)
	{
		return _instance;
	}

	//初期化
	bool Init(std::string fileName, Vec2 divSize, Vec2 divCnt, Vec2 offset, int animCnt);

	//描画用
	const VEC_INT& GetID(const std::string fileName);
	const VEC_INT& GetID(const std::string fileName, Vec2 divSize, Vec2 divCnt, Vec2 offset);

	//描画用
	void Draw(Vec2 &pos);
	//アニメーション用
	void Draw(int id);
	
};

