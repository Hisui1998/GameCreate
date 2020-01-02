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

// アプリケーションクラス。
/// シーン全体の管理や実行を行っている為、複数あると困るのでシングルトンにしている
class Application
{
private:
	// コンストラクタ
	Application();
	/// 参照コピーされないようにする
	Application(const Application&) = delete;
	/// 念のため「=」演算子もオーバーロードしておく
	void operator=(const Application&) = delete;
	// ポインタ
	static std::shared_ptr<Application> _appptr;

	// ウィンドウサイズ
	const Size wSize;

	// 現在のシーンのポインタ
	/// 複数のシーンにおいて、アニメーションのみと更新を分ける事があるためVector型にしている
	std::vector<std::unique_ptr<Scene>> _nowScenes;
public:
	~Application();

	// ポインタのインスタンス(中身がある時はそのポインタを返す)
	static std::shared_ptr<Application> Instance() {
		return _appptr;
	};

	// 初期化
	bool Init();
	// 実行
	int Run();
	// 終了
	bool End();

	// シーンの追加用
	void AddScene(std::unique_ptr<Scene> inPtr);
	// ウィンドウサイズ取得
	Size GetWindowSize();
};
