#pragma once
#include <memory>

class Scene;

// �T�C�Y�p�\����
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

	// ���݂̃V�[���̃|�C���^
	std::unique_ptr<Scene> _nowScene;
public:
	~Application();

	static std::shared_ptr<Application> Instance() {
		return _appptr;
	};

	bool Init();
	int Run();
	bool End();
};
