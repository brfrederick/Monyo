/**
	Purpose: Contains platform specific application logic and initialization
*/

#pragma once
#include <Windows.h>
#include <string>
#include "GameWindow.h"
#include "..\Util\Logger.h"


class App 
{
public:
	App();
	~App(void);

	virtual int Init();		// Create window and init game
	int InitWindow(WindowSettings settings, HINSTANCE hInstance);
	virtual int Shutdown(); // Release memory 
	int Run();				// Start the Application		

	virtual int Update() = 0;
	virtual int Render() = 0;
};
