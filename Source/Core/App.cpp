/**
Purpose: Contains Windows specific application logic and initialization
Author: Braxton Frederick
*/

#include "App.h"

App::App()
{
}

App::~App()
{
}

#pragma region Initialization 

int App::Init()
{
	Logger::Debug("App::Init");

	// Init Event Manager

	// Init InputManager (?)

	return 0;
}

int App::InitWindow(WindowSettings settings, HINSTANCE hInstance)
{
	Logger::Debug("App::Init(window,hInstance)");

	// Init window
	if (GameWindow::Get().Init(settings, hInstance) != 0) 
	{
		Logger::Debug("Window failed to initialize");
		return -1;
	}

	// Init rest of the system
	return this->Init();
}

#pragma endregion

int App::Shutdown()
{
	Logger::Debug("App::Shutdown");

	GameWindow::Get().Shutdown();

	return 0;
}

// Start the Application
int App::Run()
{
	Logger::Debug("App::Run");

	//Show window
	GameWindow::Get().Show();
	GameWindow::Get().Update();

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

