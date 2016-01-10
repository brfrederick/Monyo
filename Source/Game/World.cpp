#include "World.h"


int World::Init()
{
	Logger::Debug("World::Init");

	// For testing purposes
	m_model = AssetManager::Get().LoadModel("cube.obj");
	GraphicsManager::Get().RegisterModel(m_model);

	return 0;
}

int World::Shutdown()
{
	Logger::Debug("World::Shutdown");

	AssetManager::Get().UnloadModel(m_model);

	return 0;
}

void World::Update()
{
}

void World::Render()
{
}

