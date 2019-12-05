#pragma once
#include <DxLib.h>
#include <iostream>
#include <memory>

// シーンの仮想クラス
class Scene
{
protected:
	virtual bool init() = 0;// 初期化関数
	char _oldKey[256];// 前フレームのキーデータ格納用
	int _flame;// フレーム格納用
public:
	virtual ~Scene() {};

	virtual std::unique_ptr<Scene> UpDate(std::unique_ptr<Scene> &_this, char key[256]) = 0;
	virtual void Draw() = 0;
};
