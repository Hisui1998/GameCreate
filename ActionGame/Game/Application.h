#pragma once
#include <memory>
#include <vector>

class Scene;

// �T�C�Y�p�\����
struct Size
{
	int width;
	int height;
	Size(int width = 0, int height = 0) :width(width), height(height) {};
};

// �A�v���P�[�V�����N���X�B
/// �V�[���S�̂̊Ǘ�����s���s���Ă���ׁA��������ƍ���̂ŃV���O���g���ɂ��Ă���
class Application
{
private:
	// �R���X�g���N�^
	Application();
	/// �Q�ƃR�s�[����Ȃ��悤�ɂ���
	Application(const Application&) = delete;
	/// �O�̂��߁u=�v���Z�q���I�[�o�[���[�h���Ă���
	void operator=(const Application&) = delete;
	// �|�C���^
	static std::shared_ptr<Application> _appptr;

	// �E�B���h�E�T�C�Y
	const Size wSize;

	// ���݂̃V�[���̃|�C���^
	/// �����̃V�[���ɂ����āA�A�j���[�V�����݂̂ƍX�V�𕪂��鎖�����邽��Vector�^�ɂ��Ă���
	std::vector<std::unique_ptr<Scene>> _nowScenes;
public:
	~Application();

	// �|�C���^�̃C���X�^���X(���g�����鎞�͂��̃|�C���^��Ԃ�)
	static std::shared_ptr<Application> Instance() {
		return _appptr;
	};

	// ������
	bool Init();
	// ���s
	int Run();
	// �I��
	bool End();

	// �V�[���̒ǉ��p
	void AddScene(std::unique_ptr<Scene> inPtr);
	// �E�B���h�E�T�C�Y�擾
	Size GetWindowSize();
};
