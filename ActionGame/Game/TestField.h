#pragma once
#include "Scene.h"

class Actor;
class PrtEnemy;

//挙動チェック用のシーン（ゲーム自体では使わない）
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
	//地面と当たり判定をとるアクターへのshared_ptr, posy
	bool CheckGround(std::weak_ptr<PrtEnemy> actPtr, float& y);
	//壁と当たり判定をとるアクターへのshared_ptr, posx
	bool CheckWall(std::weak_ptr<PrtEnemy> actPtr, float& x);

	bool Init()override final;

	//各アクターのリスト
	std::vector<std::shared_ptr<PrtEnemy>> _actors;
	std::unique_ptr<Actor> _player;

	//仮マップのリスト
	std::vector<std::vector<ChipType>> _mapData;

	//当たり判定をとったアクターの位置情報をいじるための変数
	float posx, posy;

public:
	TestField();
	~TestField();
	std::unique_ptr<Scene> Update(std::unique_ptr<Scene> &_this, char key[256])override final;
	void Draw()override final;
};

