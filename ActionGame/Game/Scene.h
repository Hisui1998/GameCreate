#pragma once
#include <DxLib.h>
#include <iostream>
#include <memory>

// �V�[���̉��z�N���X
class Scene
{
protected:
	virtual bool init() = 0;// �������֐�
	char _oldKey[256];// �O�t���[���̃L�[�f�[�^�i�[�p
	int _flame;// �t���[���i�[�p
public:
	virtual ~Scene() {};

	virtual std::unique_ptr<Scene> UpDate(std::unique_ptr<Scene> &_this, char key[256]) = 0;
	virtual void Draw() = 0;
};
