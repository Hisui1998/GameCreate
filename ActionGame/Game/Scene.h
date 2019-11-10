#pragma once
#include <iostream>
#include <memory>
#include <DxLib.h>

class Scene;
using SCENE = std::unique_ptr<Scene>;

class Scene
{
protected:
	virtual bool init() = 0;
public:
	virtual ~Scene() {};

	virtual SCENE UpDate(SCENE &_this) = 0;
	virtual void Draw() = 0;
};
