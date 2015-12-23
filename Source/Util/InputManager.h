#pragma once
#include "../Util/Logger.h"
#include "../Util/Singleton.h"
#include <Windows.h>


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

class InputManager : public Singleton<InputManager>
{
public:
	int ProcessInput(UINT msg);
};

