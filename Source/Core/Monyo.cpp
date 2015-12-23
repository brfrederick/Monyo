#include "Monyo.h"


int Monyo::Init() 
{
	Logger::Debug("Monyo::Init");

	// init assetM (?)
	if (AssetManager::Get().Init() != 0)
	{
		Logger::Debug("AssetManager failed to initialize");

		return -1;
	}

	// init graphics
	if (GraphicsManager::Get().Init() != 0) 
	{
		return -1;
	}
	
	// init world
	if (World::Get().Init() != 0) 
	{
		Logger::Debug("World failed to initialize");

		return -1;
	}

	return 0;
}

int Monyo::Shutdown() 
{
	Logger::Debug("Monyo::Shutdown");

	// shutdown world
	World::Get().Shutdown();

	// shutdown graphics
	GraphicsManager::Get().Shutdown();

	// shutdown assetM (?)
	AssetManager::Get().Shutdown();

	return 0;
}

void Monyo::Update() 
{
	World::Get().Update();
}

void Monyo::Render() 
{
	GraphicsManager::Get().Render();
}