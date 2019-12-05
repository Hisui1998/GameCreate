#pragma once
#include "Scene.h"
#include <map>

class Actor;

class GameTitle:
	public Scene
{
private:
	bool init();

	// ���Ɉڍs����V�[��
	enum class NextScene
	{
		Main,// ���C��
		Config,// �R���t�B�O(�I�v�V����)
		End,// �Q�[���I��
		Max// �ő吔
	};

	int _nowSelect;// �I��

	std::unique_ptr<Actor> _player;
public:
	GameTitle();
	~GameTitle();

	virtual std::unique_ptr<Scene> UpDate(std::unique_ptr<Scene> &_this, char key[256]);
	virtual void Draw();
};

