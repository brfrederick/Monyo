/** 
	Purpose: Contain Game Module initialization and shutdown
*/

#pragma once
#include "Game.h"


Game::Game()
{
}

Game::~Game()
{
}

int Game::Init()
{
	if (App::Init() != 0)
	{
		return -1;
	}

	Logger::Debug("Game::Init");
	
	if (Monyo::Get().Init() != 0) 
	{
		return -1;
	}

	return 0;
}

// Must release in release order of initialization
int Game::Shutdown()
{
	Logger::Debug("Game::ShutDown");

	Monyo::Get().Shutdown();

	// Last, because of reverse order
	App::Shutdown();

	return 0;
}

int Game::Update() 
{
	//Logger::Debug("Game::Update");

	return 0;
}

int Game::Render() 
{
	//Logger::Debug("Game::Render");

	return 0;
}

