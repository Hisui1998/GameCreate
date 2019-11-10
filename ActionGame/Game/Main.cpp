#pragma once
#include "Application.h"

#ifdef _DEBUG
int main()
#else
#include <windows.h>
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
#endif
{
	if (!Application::Instance()->Init())return -1;
	Application::Instance()->Main();
	Application::Instance()->End();
	return 0;
}