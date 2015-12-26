#pragma once
#include <d3d11.h>

class Model 
{
public:
	Model();
	~Model();

	ID3D11Buffer** GetVertexBuffer();
	ID3D11Buffer** GetIndexBuffer();
	int GetIndexCount();

	void SetIndexCount(int value);

protected:
	int m_indexCount;
	ID3D11Buffer* m_vertexBuffer;
	ID3D11Buffer* m_indexBuffer;

};