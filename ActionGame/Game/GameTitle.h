#pragma once
#include "Scene.h"
#include <map>

class Actor;

// �^�C�g���V�[���N���X
class GameTitle:
	public Scene
{
private:
	bool Init()override final;

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

	std::unique_ptr<Scene> Update(std::unique_ptr<Scene> &_this, char key[256])override final;
	void Draw()override final;
};

