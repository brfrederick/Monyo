#include "ShaderFactory.h"

SimpleVertexShader* ShaderFactory::LoadVertexShader(std::string file) 
{
	ID3D11Device* device = GraphicsManager::Get().GetDevice();
	ID3D11DeviceContext* ctx = GraphicsManager::Get().GetContext();
	SimpleVertexShader* shader = new SimpleVertexShader(device, ctx);

	std::wstring stemp = std::wstring(file.begin(), file.end());
	shader->LoadShaderFile(stemp.c_str());

	return shader;
}

SimplePixelShader* ShaderFactory::LoadPixelShader(std::string file)
{
	ID3D11Device* device = GraphicsManager::Get().GetDevice();
	ID3D11DeviceContext* ctx = GraphicsManager::Get().GetContext();
	SimplePixelShader* shader = new SimplePixelShader(device, ctx);

	std::wstring stemp = std::wstring(file.begin(), file.end());
	shader->LoadShaderFile(stemp.c_str());

	return shader;
}

SimpleGeometryShader* ShaderFactory::LoadGeometryShader(std::string file)
{
	ID3D11Device* device = GraphicsManager::Get().GetDevice();
	ID3D11DeviceContext* ctx = GraphicsManager::Get().GetContext();
	SimpleGeometryShader* shader = new SimpleGeometryShader(device, ctx);

	std::wstring stemp = std::wstring(file.begin(), file.end());
	shader->LoadShaderFile(stemp.c_str());

	return shader;
}
