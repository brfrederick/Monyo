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
// in world after creating model push into vector
// remove from vector in world befor destorying

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

void GraphicsManager::RegisterModel(Model* model) 
{
	m_models.push_back(model);
}

void GraphicsManager::DeregisterModel(Model* model)
{
	// Come up with solution for this later
}

std::vector<Model*> GraphicsManager::GetModels()
{
	return m_models;
}
