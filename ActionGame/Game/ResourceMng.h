#pragma once
#include "Actor.h"
#include <string>
#include <vector>
#include <map>
#include <memory>

//---------------------------------------
//コード　有村
//リソースマネージャー（シングルトン）
//・画像の描画　・アニメーション
//---------------------------------------

//一枚画の描画用マクロ
#define IMAGE_ID(X) (ResourceMng::Get()->GetID(X))

//前方宣言
class Actor;
class Player;


class ResourceMng
{
private:
	//コンストラクタ
	ResourceMng();
	ResourceMng(const ResourceMng&) = delete;
	void operator=(const ResourceMng&) = delete;

	//描画する画像のファイル名を検索する連想配列クラス
	std::map<std::string, std::vector<int>> _rscMap;
	//ファイル名
	std::string _fileName;

	static std::unique_ptr<ResourceMng> _instance;

public:
	//デストラクタ
	~ResourceMng();
	static std::unique_ptr<ResourceMng> &Get(void)
	{
		return _instance;
	}

	//一枚画のリソース用
	const std::vector<int> GetID(const std::string fileName);
	//アニメーション画像用
	const std::vector<int> GetID(const std::string fileName, Vec2 divSize, Vec2 divCnt);
};

