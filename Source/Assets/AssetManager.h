#pragma once
#include <map>
#include <string.h>
#include "../Core/IModule.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"
#include "Model.h"
#include "ModelFactory.h"

class AssetManager : public IModule, public Singleton<AssetManager>
{
public:
	AssetManager() {};
	~AssetManager() {};

	virtual int Init() override;
	virtual int Shutdown() override;
	
	Model* LoadModel(std::string fileName);
	void UnloadModel(Model* model);

private:
	std::map<std::string, Model*>* m_models;
	std::map<std::string, int>* m_assetRefCount;

protected:
	std::string m_ModelDir;
};