#pragma once
#include <DxLib.h>
#include <iostream>
#include <memory>
#include <map>
#include <vector>

// �V�[���̉��z�N���X
class Scene
{
protected:
	// �������֐�
	virtual bool Init() = 0;

	// �������u�Ԃ��擾����֐�
	bool CheckKeyTrigger(const char key[256],const int& checkInputKey);

	// �L�[�f�[�^�i�[�p
	char _key[256];
	char _oldKey[256];

	// �`��p�t���[���i�[�p
	int _drawFlame;
	// �{�^��������L�[�ԍ����擾����
	static std::map<std::string, int> _keyState;
	const std::vector<std::string> KeyName;
public:
	Scene();
	virtual ~Scene() {};

	// ��񂾂��ĂԂ��ׂĂɋ��ʂ��鏉����
	void PreAllInit();
	// �X�V�p
	virtual std::unique_ptr<Scene> Update(std::unique_ptr<Scene> &_this, char key[256]) = 0;
	// �`��p
	virtual void Draw() = 0;
};
