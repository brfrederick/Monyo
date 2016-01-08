#include "World.h"
#include "Model.h"
#include "../Assets/AssetManager.h"

int World::Init()
{
	Logger::Debug("World::Init");

	// For testing purposes
	model = AssetManager::Get().LoadModel("cube.obj");

	return 0;
}

int World::Shutdown()
{
	Logger::Debug("World::Shutdown");

	delete model;

	return 0;
}

void World::Update()
{
}

void World::Render()
{
}

