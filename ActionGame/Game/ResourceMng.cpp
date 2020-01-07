#include "ResourceMng.h"

std::unique_ptr<ResourceMng> ResourceMng::_instance(new ResourceMng());


//コンストラクタ
ResourceMng::ResourceMng()
{
}
//デストラクタ
ResourceMng::~ResourceMng()
{
}


//一枚画のリソース用
//リソースIDの読み込みとハンドル作成
const std::vector<int> ResourceMng::GetID(std::string fileName)
{
	//ファイル名検索
	if (_rscMap.find(fileName) == _rscMap.end())
	{
		_rscMap[fileName].resize(1);
		_rscMap[fileName][0] = LoadGraph(fileName.c_str());
	}

	//作成したハンドルを返す
	return _rscMap[fileName];		
}

//アニメーション描画用
//リソースIDの読み込みとハンドル作成
//divSize : 分割したい画像のサイズ,　divCnt : 画像の分割数
const std::vector<int> ResourceMng::GetID(std::string fileName, Vec2 divSize, Vec2 divCnt)
{
	//ファイル名検索
	if (_rscMap.find(fileName) == _rscMap.end())
	{
		_rscMap[fileName].resize(divCnt.x * divCnt.y);
		LoadDivGraph(fileName.c_str(),divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &_rscMap[fileName][0], true);
	}

	//作成したハンドルを返す
	return _rscMap[fileName];
}