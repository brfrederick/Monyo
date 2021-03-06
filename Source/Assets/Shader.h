/*
 *  Shader.h authored by Chris Cascioli
*/

#pragma once
#pragma comment(lib, "dxguid.lib")

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#include <unordered_map>
#include <string>

// --------------------------------------------------------
// Used by simple shaders to store information about
// specific variables in constant buffers
// --------------------------------------------------------
struct ShaderVariable
{
	unsigned int ByteOffset;
	unsigned int Size;
	unsigned int ConstantBufferIndex;
};

// --------------------------------------------------------
// Contains information about a specific
// constant buffer in a shader, as well as
// the local data buffer for it
// --------------------------------------------------------
struct SimpleConstantBuffer
{
	unsigned int BindIndex;
	ID3D11Buffer* ConstantBuffer;
	unsigned char* LocalDataBuffer;
};

// --------------------------------------------------------
// Base abstract class for simplifying shader handling
// --------------------------------------------------------
class IShader
{
public:
	IShader(ID3D11Device* device, ID3D11DeviceContext* context);
	virtual ~IShader();

	// Initialization method (since we can't invoke derived class
	// overrides in the base class constructor)
	bool LoadShaderFile(LPCWSTR shaderFile);

	// Simple helpers
	bool IsShaderValid() { return shaderValid; }

	// Activating the shader and copying data
	void SetShader(bool copyData = true);
	void CopyAllBufferData();
	void CopyBufferData(std::string bufferName);

	// Sets arbitrary shader data
	bool SetData(std::string name, const void* data, unsigned int size);

	bool SetInt(std::string name, int data);
	bool SetFloat(std::string name, float data);
	bool SetFloat2(std::string name, const float data[2]);
	bool SetFloat2(std::string name, const DirectX::XMFLOAT2 data);
	bool SetFloat3(std::string name, const float data[3]);
	bool SetFloat3(std::string name, const DirectX::XMFLOAT3 data);
	bool SetFloat4(std::string name, const float data[4]);
	bool SetFloat4(std::string name, const DirectX::XMFLOAT4 data);
	bool SetMatrix4x4(std::string name, const float data[16]);
	bool SetMatrix4x4(std::string name, const DirectX::XMFLOAT4X4 data);

	// Setting shader resources
	virtual bool SetShaderResourceView(std::string name, ID3D11ShaderResourceView* srv) = 0;
	virtual bool SetSamplerState(std::string name, ID3D11SamplerState* samplerState) = 0;

protected:

	bool shaderValid;
	ID3D11Device* device;
	ID3D11DeviceContext* deviceContext;

	// Constant buffers and related data buffers
	unsigned int constantBufferCount;

	// Maps for variables and buffers
	SimpleConstantBuffer* constantBuffers; // For index-based lookup
	std::unordered_map<std::string, SimpleConstantBuffer*> cbTable;
	std::unordered_map<std::string, ShaderVariable> varTable;
	std::unordered_map<std::string, unsigned int> textureTable;
	std::unordered_map<std::string, unsigned int> samplerTable;

	// Pure virtual functions for dealing with shader types
	virtual bool CreateShader(ID3DBlob* shaderBlob) = 0;
	virtual void SetShaderAndCB() = 0;

	virtual void CleanUp();

	// Helpers for finding data by name
	ShaderVariable* FindVariable(std::string name, int size);
	SimpleConstantBuffer* FindConstantBuffer(std::string name);
	unsigned int FindTextureBindIndex(std::string name);
	unsigned int FindSamplerBindIndex(std::string name);
};

// --------------------------------------------------------
// Derived class for VERTEX shaders ///////////////////////
// --------------------------------------------------------
class SimpleVertexShader : public IShader
{
public:
	SimpleVertexShader(ID3D11Device* device, ID3D11DeviceContext* context);
	~SimpleVertexShader();
	ID3D11VertexShader* GetDirectXShader() { return shader; }
	ID3D11InputLayout* GetInputLayout() { return inputLayout; }

	bool SetShaderResourceView(std::string name, ID3D11ShaderResourceView* srv);
	bool SetSamplerState(std::string name, ID3D11SamplerState* samplerState);

protected:
	ID3D11InputLayout* inputLayout;
	ID3D11VertexShader* shader;
	bool CreateShader(ID3DBlob* shaderBlob);
	void SetShaderAndCB();
	void CleanUp();
};


// --------------------------------------------------------
// Derived class for PIXEL shaders ////////////////////////
// --------------------------------------------------------
class SimplePixelShader : public IShader
{
public:
	SimplePixelShader(ID3D11Device* device, ID3D11DeviceContext* context);
	~SimplePixelShader();
	ID3D11PixelShader* GetDirectXShader() { return shader; }

	bool SetShaderResourceView(std::string name, ID3D11ShaderResourceView* srv);
	bool SetSamplerState(std::string name, ID3D11SamplerState* samplerState);

protected:
	ID3D11PixelShader* shader;
	bool CreateShader(ID3DBlob* shaderBlob);
	void SetShaderAndCB();
	void CleanUp();
};

// --------------------------------------------------------
// Derived class for GEOMETRY shaders /////////////////////
// --------------------------------------------------------
class SimpleGeometryShader : public IShader
{
public:
	SimpleGeometryShader(ID3D11Device* device, ID3D11DeviceContext* context, bool useStreamOut = 0, bool allowStreamOutRasterization = 0);
	~SimpleGeometryShader();
	ID3D11GeometryShader* GetDirectXShader() { return shader; }

	bool SetShaderResourceView(std::string name, ID3D11ShaderResourceView* srv);
	bool SetSamplerState(std::string name, ID3D11SamplerState* samplerState);

	bool CreateCompatibleStreamOutBuffer(ID3D11Buffer** buffer, int vertexCount);

	static void UnbindStreamOutStage(ID3D11DeviceContext* deviceContext);

protected:
	// Shader itself
	ID3D11GeometryShader* shader;

	// Stream out related
	bool useStreamOut;
	bool allowStreamOutRasterization;
	unsigned int streamOutVertexSize;

	bool CreateShader(ID3DBlob* shaderBlob);
	bool CreateShaderWithStreamOut(ID3DBlob* shaderBlob);
	void SetShaderAndCB();
	void CleanUp();

	// Helpers
	unsigned int CalcComponentCount(unsigned int mask);
};