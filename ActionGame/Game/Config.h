#pragma once
#include "Scene.h"

// コンフィグシーンクラス
class Config:
	public Scene
{
private:
	bool Init()override final;

	void ChangeKeyUpdate(const char key[256]);

	// キー情報の変更
	bool ChangeKeyState(const std::string& stateName, const int& keyValue);
	// 変更中かどうかの確認フラグ
	bool _isChange;
	// 変更中のキー
	int _changeKeyNum;
public:
	Config();
	~Config();

	std::unique_ptr<Scene> Update(std::unique_ptr<Scene> &_this, char key[256])override final;
	void Draw()override final;
};

