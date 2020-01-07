#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Actor.h"


//MapChipの種類
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

//前方宣言
class Actor;

class MapMng
{
private:
	//コンストラクタ
	MapMng();
	MapMng(const MapMng&) = delete;
	void operator=(const MapMng&) = delete;

	std::string convertPathFormatToUnixStyle(const std::string& path);

	//実体生成
	static std::unique_ptr<MapMng> _instance;

	//読み込んだマップリストのデータ
	std::vector<std::vector<MapData>> _mapData;

	//当たり判定をとったアクターの位置情報をいじるための変数
	float posx, posy;

	//マップチップ一枚当たりのサイズ
	int sizex, sizey;

	//マップの全体のサイズ
	int fieldx, fieldy;

public:
	~MapMng();

	static std::unique_ptr<MapMng>& Get(void)
	{
		return _instance;
	}

	//読み込むマップの名前
	bool RoadMap(std::string mapName);

	//フィールドとの当たり判定用関数
	//地面と当たり判定をとるアクターへのshared_ptr, posy
	bool CheckGround(std::weak_ptr<Actor> actPtr, float& y);
	//壁と当たり判定をとるアクターへのshared_ptr, posx
	bool CheckWall(std::weak_ptr<Actor> actPtr, float& x);
};

