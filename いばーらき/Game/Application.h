#pragma once
#include <memory>

class Scene;

// サイズ用構造体
struct Size
{
	int width;
	int height;
	Size(int width = 0, int height = 0) :width(width), height(height) {};
};

class Application
{
private:
	Application();
	static std::shared_ptr<Application> _appptr;
	int idx = 0;
	std::unique_ptr<Scene> NowScene;
	const Size wSize;
public:
	~Application();

	static std::shared_ptr<Application> Instance() {
		return _appptr;
	};

	bool Init();
	int Main();
	bool End();
};
