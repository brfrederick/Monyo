#include "GraphicsManager.h"

int GraphicsManager::Init() 
{
	Logger::Debug("GraphicsManager::Init");
	
	m_renderer = Renderer();
	if (m_renderer.Init() != 0)
	{
		return -1;
	}

	return 0;
}

int GraphicsManager::Shutdown()
{
	Logger::Debug("GraphicsManager::Shutdown");

	m_renderer.Shutdown();

	return 0;
}

void GraphicsManager::Update() 
{
	// filter geometry 
}

void GraphicsManager::Render()
{
	m_renderer.Render();
}

