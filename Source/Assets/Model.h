#pragma once
#include <d3d11.h>
#include <string>

class Model 
{
public:
	Model(std::string assetId);
	~Model();

	void Unload();

	ID3D11Buffer** GetVertexBuffer();
	ID3D11Buffer** GetIndexBuffer();
	int GetIndexCount();
	std::string GetAssetID();
	void SetIndexCount(int value);

protected:
	std::string m_assetId;
	int m_indexCount;
	ID3D11Buffer* m_vertexBuffer;
	ID3D11Buffer* m_indexBuffer;

};