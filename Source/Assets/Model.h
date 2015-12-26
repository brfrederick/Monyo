#pragma once
#include <d3d11.h>

class Model 
{
public:
	Model() {};
	~Model() {};

	ID3D11Buffer** GetVertexBuffer() { return &m_vertexBuffer; }
	ID3D11Buffer* GetIndexBuffer() { return m_indexBuffer; }
	int GetIndexCount() { return m_indexCount; }

protected:
	int m_indexCount;
	ID3D11Buffer* m_vertexBuffer;
	ID3D11Buffer* m_indexBuffer;

};