#include "Model.h"

Model::Model() 
	: m_indexCount(0), m_vertexBuffer(0), m_indexBuffer(0)
{

}

Model::~Model() 
{

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

void Model::SetIndexCount(int value)
{
	m_indexCount = value;
}

