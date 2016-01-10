#include "Model.h"

Model::Model(std::string assetId) : m_assetId(assetId), m_indexCount(0), m_vertexBuffer(0), m_indexBuffer(0)
{

}

Model::~Model() 
{

}

void Model::Unload() 
{
	//AssetManager::Get(); // UnloadModel( m_assetId );
}

ID3D11Buffer** Model::GetVertexBuffer() 
{
	return &m_vertexBuffer;
}

ID3D11Buffer** Model::GetIndexBuffer() 
{
	return &m_indexBuffer;
}

int Model::GetIndexCount() 
{
	return m_indexCount;
}

std::string Model::GetAssetID() 
{
	return m_assetId;
}

void Model::SetIndexCount(int value)
{
	m_indexCount = value;
}

