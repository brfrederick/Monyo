#include "AssetManager.h"

int AssetManager::Init()
{
	Logger::Debug("AssetManager::Init");

	m_ModelDir = "../Assets/Models/";
	m_ShaderDir = "../Assets/Shaders/";
	m_models = new std::map<std::string, Model*>();
	m_assetRefCount = new std::map<std::string, int>();
	m_vertexShaders = new std::map<std::string, SimpleVertexShader*>();
	m_pixelShaders = new std::map<std::string, SimplePixelShader*>();
	m_geometryShaders = new std::map<std::string, SimpleGeometryShader*>();

	return 0;
}

int AssetManager::Shutdown()
{
	Logger::Debug("AssetManager::Shutdown");

	delete m_models;
	delete m_assetRefCount;
	delete m_vertexShaders;
	delete m_pixelShaders;
	delete m_geometryShaders;

	return 0;
}

SimpleVertexShader* AssetManager::LoadVertexShader(std::string fileName)
{
	if (m_vertexShaders->count(m_ShaderDir + fileName) == 0)
	{

	}
}

SimplePixelShader* AssetManager::LoadPixelShader(std::string fileName)
{
	if (m_pixelShaders->count(m_ShaderDir + fileName) == 0)
	{

	}
}

SimpleGeometryShader* AssetManager::LoadGeometryShader(std::string fileName)
{
	if (m_geometryShaders->count(m_ShaderDir + fileName) == 0)
	{

	}
}

Model* AssetManager::LoadModel(std::string fileName) 
{
	// If the model exists, add it to the models dictionary, set the ref count dictionary, and return the model
	// Otherwise just increment the ref count and return the existing model
	if (m_models->count(m_ModelDir + fileName) == 0) 
	{
		m_models->insert({ m_ModelDir + fileName, ModelFactory::BuildModel(m_ModelDir + fileName) });
		m_assetRefCount->insert({ m_ModelDir + fileName, 1 });
		return (*m_models)[m_ModelDir + fileName];
	}
	else if (m_models->count(m_ModelDir + fileName) == 1) 
	{
		(*m_assetRefCount)[m_ModelDir + fileName]++;
		return (*m_models)[m_ModelDir + fileName];
	}
} 

void AssetManager::UnloadModel(Model* model)
{
	std::string assetId = model->GetAssetID();

	(*m_assetRefCount)[assetId]--;

	if ((*m_assetRefCount)[m_ModelDir] == 0)
	{
		m_models->erase(assetId);
		m_assetRefCount->erase(assetId);
	}
}