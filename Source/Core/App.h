/**
	Purpose: Contains platform specific application logic and initialization
*/

#pragma once
#include <Windows.h>
#include <string>
#include "..\Util\Logger.h"

// Windows message handler
LRESULT CALLBACK WndMsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Store window parameters
struct WindowSettings {
	int width;
	int height;
	bool minimized;
	bool maximized;
	bool resizing;
	std::string title;
};

class App 
{
public:
	App(WindowSettings settings, HINSTANCE hInstance);
	~App(void);

	virtual int Init();		// Create window and init game
	virtual int Shutdown(); // Release memory 
	int Run();				// Start the Application		

	virtual int Update() = 0;
	virtual int Render() = 0;

protected:

	HINSTANCE hInstance;
	HWND hMainWnd;
	WindowSettings m_settings;

	// Platform Specific Application Initialization 
	int InitWindow();
};