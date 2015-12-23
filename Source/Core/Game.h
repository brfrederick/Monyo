/**
Purpose: Contain Game Module initialization and shutdown
*/

#pragma once
#include "App.h"
#include "Monyo.h"

class Game : public App
{
public:
	Game();
	~Game(void);

	virtual int Init() override;
	virtual int Shutdown() override;
	virtual int Update() override;
	virtual int Render() override;
};

