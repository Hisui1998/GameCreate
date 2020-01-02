#pragma once
#include "Scene.h"

class Actor;
class PrtEnemy;

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
	//フィールドとの当たり判定用関数
	bool CheckGround(std::weak_ptr<PrtEnemy> actPtr, float& y);
	bool CheckWall(std::weak_ptr<PrtEnemy> actPtr, float& x);

	bool Init()override final;
	std::vector<std::shared_ptr<PrtEnemy>> _actors;
	std::unique_ptr<Actor> _player;
	std::vector<std::vector<ChipType>> _mapData;
	float posx, posy;

public:
	TestField();
	~TestField();
	std::unique_ptr<Scene> Update(std::unique_ptr<Scene> &_this, char key[256])override final;
	void Draw()override final;
};

