#pragma once
#include <iostream>
#include <memory>
#include <DxLib.h>

class Scene
{
protected:
	virtual bool init() = 0;

public:
	virtual ~Scene() {};

	virtual void UpDate() = 0;
};
