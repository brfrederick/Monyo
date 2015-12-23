#pragma once
#include <Windows.h>
#include <string>
#include "IModule.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"
#include "../Input/InputManager.h"


// Store window parameters
struct WindowSettings {
	int width;
	int height;
	bool minimized;
	bool maximized;
	bool resizing;
	std::string title;
};

class GameWindow : public IModule, public Singleton<GameWindow>
{

public:

	virtual int Init() override;
	int Init(WindowSettings, HINSTANCE hInstance);
	virtual int Shutdown() override;

	HINSTANCE GetHInstance();
	HWND GetHandle();

	void Show();
	void Update();

protected:
	HINSTANCE m_hInstance;
	HWND m_hMainWnd;
	WindowSettings m_settings;
};