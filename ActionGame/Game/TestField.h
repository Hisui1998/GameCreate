#pragma once
#include "Scene.h"

class Actor;
class PrtEnemy;

//�����`�F�b�N�p�̃V�[���i�Q�[�����̂ł͎g��Ȃ��j
enum class ChipType
{
	BLANK,
	WALL,
	GROUND,
	MAX
};

class TestField :
	public Scene
{
private:
	//�t�B�[���h�Ƃ̓����蔻��p�֐�
	//�n�ʂƓ����蔻����Ƃ�A�N�^�[�ւ�shared_ptr, posy
	bool CheckGround(std::weak_ptr<PrtEnemy> actPtr, float& y);
	//�ǂƓ����蔻����Ƃ�A�N�^�[�ւ�shared_ptr, posx
	bool CheckWall(std::weak_ptr<PrtEnemy> actPtr, float& x);

	bool Init()override final;

	//�e�A�N�^�[�̃��X�g
	std::vector<std::shared_ptr<PrtEnemy>> _actors;
	std::unique_ptr<Actor> _player;

	//���}�b�v�̃��X�g
	std::vector<std::vector<ChipType>> _mapData;

	//�����蔻����Ƃ����A�N�^�[�̈ʒu���������邽�߂̕ϐ�
	float posx, posy;

public:
	TestField();
	~TestField();
	std::unique_ptr<Scene> Update(std::unique_ptr<Scene> &_this, char key[256])override final;
	void Draw()override final;
};

