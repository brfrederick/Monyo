/**
Purpose: Contains Windows specific application logic and initialization
Author: Braxton Frederick
*/

#include "App.h"

// @TODO move to an input handler
LRESULT CALLBACK WndMsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg)
	{
	case WM_LBUTTONDOWN:
		MessageBox(0, L"Mouse Input", L"Left button clicked", MB_OK);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

App::App(WindowSettings settings, HINSTANCE hInstance)
	: hInstance(hInstance), 
	m_settings(settings)
{
}

App::~App()
{
}

#pragma region Initialization 

int App::Init()
{
	Logger::Debug("App::Init");

	//Windows application specific initalization
	if (this->InitWindow() != 0) 
	{
		return -1;
	}

	// Init Logger

	// Init Event Manager

	// Init InputManager (?)

	return 0;
}

//Windows application specific initalization
int App::InitWindow()
{
	Logger::Debug("App::InitWindow");

	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndMsgProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->hInstance;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"AppWndClass";

	if (!RegisterClass(&wc)) 
	{
		return -1;	 // Register Class Failed
	}

	RECT bounds = { 0, 0, m_settings.width, m_settings.height };
	AdjustWindowRect(&bounds, WS_OVERLAPPEDWINDOW, false);
	int width = bounds.right - bounds.left;
	int height = bounds.bottom - bounds.top;

	// Convert string to a LPCWSTR 
	std::wstring stemp = std::wstring(m_settings.title.begin(), m_settings.title.end());
	LPCWSTR swTitle = stemp.c_str();

	this->hMainWnd = CreateWindow(
		L"AppWndClass",
		swTitle,	 
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		width,
		height,
		0,
		0,
		this->hInstance,
		0
		);

	if (this->hMainWnd == 0) {
		return -1;	// Create window failed
	}

	return 0;
}

#pragma endregion

// Start the Application
// @NOTE add params, two callbacks, update and draw? game::run calls base.run passing
//		the callbacks to properly trigger the loop?
// @NOTE virtualize update and draw functions, game override them but not RUN ?
// @NOTE might be better to utilize the EventManager and trigger update and draw events
//		Other systems like World and GraphicsM. would be listening to the events
int App::Run()
{
	Logger::Debug("App::Run");

	//Show window
	ShowWindow(this->hMainWnd, 1);
	UpdateWindow(this->hMainWnd);

	MSG msg = { 0 };
	BOOL bContinue = 1;

	while ((bContinue = GetMessage(&msg, 0, 0, 0)) != 0)
	{
		if (bContinue == -1)
		{
			// Get Message Failed
			break;
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			this->Update();
			this->Render();
		}
	}

	this->Shutdown();
	return (int)msg.wParam;
}

int App::Shutdown() 
{
	Logger::Debug("App::Shutdown");

	return 0;
}