/**
Purpose: Contain Game Module initialization and shutdown
*/

#pragma once
#include "App.h"

class Game : public App
{
public:
	Game(WindowSettings settings, HINSTANCE hInstance);
	~Game(void);

	virtual int Init() override;
	virtual int Shutdown() override;
	virtual int Update() override;
	virtual int Render() override;
};

