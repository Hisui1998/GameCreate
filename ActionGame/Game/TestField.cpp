#include "TestField.h"
#include "Enemy.h"
#include "Player.h"


//マジックナンバー40はマップチップの大きさ

TestField::TestField()
{
	if (Init()) std::cout << "テストフィールド初期化完了" << std::endl;
	else std::cout << "テストフィールド初期化失敗" << std::endl;
}

TestField::~TestField()
{
}


bool TestField::CheckGround(std::weak_ptr<PrtEnemy> actPtr, float& y)
{
	//当たり判定をとっているか確認するための座標(足下の座標)
	Vec2 checkPos = Vec2(actPtr.lock()->GetPos().x + actPtr.lock()->GetSize().x / 2,
						 actPtr.lock()->GetPos().y + actPtr.lock()->GetSize().y);

	if (_mapData[(int)checkPos.y / 40][(int)checkPos.x / 40] == ChipType::GROUND)
	{
		y = ((int)actPtr.lock()->GetPos().y / 40) * 40 + (40 - actPtr.lock()->GetSize().y);
		return true;
	}
	return false;
}

bool TestField::CheckWall(std::weak_ptr<PrtEnemy> actPtr, float & x)
{
	//当たり判定をとっているか確認するための座標(向いている方向の端)
	Vec2 checkPos = Vec2(actPtr.lock()->GetPos().x + actPtr.lock()->GetSize().x / 2 + actPtr.lock()->GetDir().x * actPtr.lock()->GetSize().x / 2,
						 actPtr.lock()->GetPos().y + actPtr.lock()->GetSize().y / 2);

	if (_mapData[(int)checkPos.y / 40][(int)checkPos.x / 40] == ChipType::WALL)
	{
		x = ((int)checkPos.x / 40) * 40 - actPtr.lock()->GetDir().x * 40;
		return true;
	}
	return false;
}

bool TestField::Init()
{
	_player = std::make_unique<Player>();
	_actors.emplace_back(std::make_shared<Enemy>(Vec2(200,100), Vec2(30, 30)));

	_mapData.resize(600 / 40);
	for (int y = 0; y < 15; y++)
	{
		_mapData[y].resize(800 / 40);
	}

	for (int x = 0; x < 20; x++)
	{
		_mapData[12][x] = ChipType::GROUND;
	}

	for (int y = 0; y < 15; y++)
	{
		_mapData[y][0] = ChipType::WALL;
		_mapData[y][15] = ChipType::WALL;
	}

	posy = 0;

	return true;
}

std::unique_ptr<Scene> TestField::Update(std::unique_ptr<Scene>& _this, char key[256])
{
	_player->UpDate(key);

	for (auto enemy : _actors)
	{
		enemy->UpDate(key);
		enemy->CheckBlock(CheckGround(enemy, posy), CheckWall(enemy, posx), posx, posy);
	}

	return std::move(_this);
}

void TestField::Draw()
{
	_drawFlame++;

	_player->Draw();

	for (auto enemy : _actors)
	{
		enemy->Draw();
	}

	for (int y = 0; y < _mapData.size(); y++)
	{
		for (int x = 0; x < _mapData[y].size(); x++)
		{
			if (_mapData[y][x] == ChipType::GROUND)
			{
				DrawBox(x * 40, y * 40, x * 40 + 40, y * 40 + 40, 0xff0000, true);
			}
			else if (_mapData[y][x] == ChipType::WALL)
			{
				DrawBox(x * 40, y * 40, x * 40 + 40, y * 40 + 40, 0x00ff00, true);
			}
		}
	}

	

	DrawString(0, 0, "TestField", 0xffffff);
}
