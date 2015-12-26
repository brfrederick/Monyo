#include "AssetManager.h"

int AssetManager::Init()
{
	Logger::Debug("AssetManager::Init");

	return 0;
}

int AssetManager::Shutdown()
{
	Logger::Debug("AssetManager::Shutdown");

	return 0;
}

Model* AssetManager::LoadModel(char* fileName) 
{
	return ModelFactory::BuildModel(fileName);
}

