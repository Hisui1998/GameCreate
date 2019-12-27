#pragma once
#include "Scene.h"

// �R���t�B�O�V�[���N���X
class Config:
	public Scene
{
private:
	bool Init()override final;

	void ChangeKeyUpdate(const char key[256]);

	// �L�[���̕ύX
	bool ChangeKeyState(const std::string& stateName, const int& keyValue);
	// �ύX�����ǂ����̊m�F�t���O
	bool _isChange;
	// �ύX���̃L�[
	int _changeKeyNum;
public:
	Config();
	~Config();

	std::unique_ptr<Scene> Update(std::unique_ptr<Scene> &_this, char key[256])override final;
	void Draw()override final;
};

