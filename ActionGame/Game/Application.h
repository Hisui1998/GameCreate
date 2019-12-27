#pragma once
#include <memory>
#include <vector>

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
	const Size wSize;

	// 現在のシーンのポインタ
	std::vector<std::unique_ptr<Scene>> _nowScenes;
public:
	~Application();

	static std::shared_ptr<Application> Instance() {
		return _appptr;
	};

	bool Init();
	int Run();
	bool End();
	void AddScene(std::unique_ptr<Scene> inPtr);
};
