#pragma once
#include <map>
#include <string.h>
#include "../Core/IModule.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"
#include "Model.h"
#include "ModelFactory.h"
#include "Shader.h"

class AssetManager : public IModule, public Singleton<AssetManager>
{
public:
	AssetManager() {};
	~AssetManager() {};

	virtual int Init() override;
	virtual int Shutdown() override;
	
	Model* LoadModel(std::string fileName);
	void UnloadModel(Model* model);

	SimpleVertexShader* LoadVertexShader(std::string fileName);
	SimplePixelShader* LoadPixelShader(std::string fileName);
	SimpleGeometryShader* LoadGeometryShader(std::string fileName);

private:
	std::map<std::string, Model*>* m_models;
	std::map<std::string, int>* m_assetRefCount;
	std::map<std::string, SimpleVertexShader*>* m_vertexShaders;
	std::map<std::string, SimplePixelShader*>* m_pixelShaders;
	std::map<std::string, SimpleGeometryShader*>* m_geometryShaders;

protected:
	std::string m_ModelDir;
	std::string m_ShaderDir;
};