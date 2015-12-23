#pragma once
#include "../Core/IModule.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"

class AssetManager : public IModule, public Singleton<AssetManager>
{
public:
	AssetManager() {};
	~AssetManager() {};

	virtual int Init() override;
	virtual int Shutdown() override;

	void Update();
	void Render();
};