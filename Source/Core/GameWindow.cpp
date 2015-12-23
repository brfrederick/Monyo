#include "GameWindow.h"

// Window specific callback, must be outside an object
LRESULT CALLBACK WndMsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	// Handle Windows specific logic
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		MessageBox(0, L"Mouse Input", L"Left button clicked", MB_OK);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	// Handle Game related logic
	if (InputManager::Get().ProcessInput(msg) == 0)
	{
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int GameWindow::Init()
{
	Logger::Debug("GameWindow::Init");

	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndMsgProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hInstance;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"AppWndClass";

	if (!RegisterClass(&wc))
	{
		Logger::Debug("Registering Class failed");
		return -1;
	}

	RECT bounds = { 0, 0, m_settings.width, m_settings.height };
	AdjustWindowRect(&bounds, WS_OVERLAPPEDWINDOW, false);
	int width = bounds.right - bounds.left;
	int height = bounds.bottom - bounds.top;

	// Convert string to a LPCWSTR 
	std::wstring stemp = std::wstring(m_settings.title.begin(), m_settings.title.end());
	LPCWSTR swTitle = stemp.c_str();

	m_hMainWnd = CreateWindow(
		L"AppWndClass",
		swTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		width,
		height,
		0,
		0,
		m_hInstance,
		0
		);

	if (m_hMainWnd == 0) {
		Logger::Debug("Create Window Failed");
		return -1;
	}


	return 0;
}

int GameWindow::Init(WindowSettings settings, HINSTANCE hInstance) 
{
	m_settings = settings;
	m_hInstance = hInstance;
	
	return Init();
}

int GameWindow::Shutdown()
{
	return 0;
}

HINSTANCE GameWindow::GetHInstance() 
{
	return m_hInstance;
}

HWND GameWindow::GetHandle() 
{
	return m_hMainWnd;
}

void GameWindow::Show()
{
	ShowWindow(m_hMainWnd, 1);
}

void GameWindow::Update()
{
	UpdateWindow(m_hMainWnd);
}
