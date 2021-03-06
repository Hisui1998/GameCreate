#pragma once
#include <DxLib.h>
#include <iostream>
#include <memory>
#include <map>
#include <vector>

// シーンの仮想クラス
class Scene
{
protected:
	// 初期化関数
	virtual bool Init() = 0;

	// 押した瞬間を取得する関数
	bool CheckKeyTrigger(const char key[256],const int& checkInputKey);

	// キーデータ格納用
	char _key[256];
	char _oldKey[256];

	// 描画用フレーム格納用
	int _drawFlame;

	// ボタン名からキー番号を取得する
	static std::map<std::string, int> _keyState;

	// ボタン名を入れてる
	const std::vector<std::string> KeyName;
public:
	Scene();
	virtual ~Scene() {};

	// 一回だけ呼ぶすべてに共通する初期化
	void PreAllInit();

	// キー情報取得関数
	// name:キーの名前
	// 引数で受け取った名前に割り当てられているキー番号が返ってくる
	// 名前にキー番号が割り当てられていない場合-1が返ってくる
	int GetKey(std::string name);

	/// _this:現在のシーンのポインタ
	/// key:キー入力情報
	/// 変更がない場合は引数で受け取っている_thisを返す。
	/// 変更がある場合は返り値に次のシーンとなるポインタを返す。
	// 更新用
	virtual std::unique_ptr<Scene> Update(std::unique_ptr<Scene> &_this, char key[256]) = 0;

	// 描画用
	virtual void Draw() = 0;
};
