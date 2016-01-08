#include "World.h"


int World::Init()
{
	Logger::Debug("World::Init");

	// For testing purposes
	m_model = AssetManager::Get().LoadModel("cube.obj");

	return 0;
}

int World::Shutdown()
{
	Logger::Debug("World::Shutdown");

	delete m_model;

	return 0;
}

void World::Update()
{
}

void World::Render()
{
}

