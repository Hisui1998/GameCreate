#include "MapMng.h"
#include "Actor.h"

std::unique_ptr<MapMng> MapMng::_instance(new MapMng());


MapMng::MapMng()
{
}


MapMng::~MapMng()
{
}

bool MapMng::RoadMap(std::string mapName)
{
	std::string full_Path = "";

	//�t���p�X�쐬�̃v���Z�X
	{
		WCHAR utf16Path[512] = { 0 };
		GetModuleFileNameW(NULL, utf16Path, 511);

		WCHAR* utf16ExePath = &(utf16Path[0]);

		WCHAR* utf16DirEnd = wcsrchr(utf16ExePath, L'\\');

		char utf8ExeDir[512] = { 0 };

		WideCharToMultiByte(CP_UTF8, 0, utf16ExePath, utf16DirEnd - utf16ExePath + 1, utf8ExeDir, sizeof(utf8ExeDir), nullptr, nullptr);

		full_Path = convertPathFormatToUnixStyle(utf8ExeDir) + "mapdata/" + mapName + ".tmx";
	}

	FILE* file;
	auto error = fopen_s(&file, full_Path.c_str(), "rb");
	if (error != 0)
	{
		std::cout << "�t�B�[���h���������s" << std::endl;
		return false;
	}

	//Tiled�ō쐬����mapdata�̓ǂݍ��݃v���Z�X
	std::cout << "�t�B�[���h����������" << std::endl;
	return true;
}

bool MapMng::CheckGround(std::weak_ptr<Actor> actPtr, float& y)
{
	//�����蔻����Ƃ��Ă��邩�m�F���邽�߂̍��W(�����̍��W)
	Vec2 checkPos = Vec2(actPtr.lock()->GetPos().x + actPtr.lock()->GetSize().x / 2,
		actPtr.lock()->GetPos().y + actPtr.lock()->GetSize().y);

	if (_mapData[(int)checkPos.y / sizey][(int)checkPos.x / sizex].type == ChipTypeB::GROUND)
	{
		y = ((int)actPtr.lock()->GetPos().y / sizey) * sizey + (sizex - actPtr.lock()->GetSize().y);
		return true;
	}
	return false;
}

bool MapMng::CheckWall(std::weak_ptr<Actor> actPtr, float & x)
{
	//�����蔻����Ƃ��Ă��邩�m�F���邽�߂̍��W(�����Ă�������̒[)
	Vec2 checkPos = Vec2(actPtr.lock()->GetPos().x + actPtr.lock()->GetSize().x / 2 + actPtr.lock()->GetDir().x * actPtr.lock()->GetSize().x / 2,
		actPtr.lock()->GetPos().y + actPtr.lock()->GetSize().y / 2);

	if (_mapData[(int)checkPos.y / sizey][(int)checkPos.x / sizex].type == ChipTypeB::WALL)
	{
		x = ((int)checkPos.x / sizex) * sizex - actPtr.lock()->GetDir().x * sizex;
		return true;
	}
	return false;
}


std::string MapMng::convertPathFormatToUnixStyle(const std::string & path)
{
	std::string ret = path;
	int len = ret.length();
	for (int i = 0; i < len; ++i)
	{
		if (ret[i] == '\\')
		{
			ret[i] = '/';
		}
	}
	return ret;
}
