#pragma once
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

protected:

	std::string m_ModelDir;
};