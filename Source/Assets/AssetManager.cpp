#include "AssetManager.h"

int AssetManager::Init()
{
	Logger::Debug("AssetManager::Init");

	m_ModelDir = "../Assets/Models/";

	return 0;
}

int AssetManager::Shutdown()
{
	Logger::Debug("AssetManager::Shutdown");

	return 0;
}

Model* AssetManager::LoadModel(std::string fileName) 
{

	return ModelFactory::BuildModel(m_ModelDir + fileName);
}

