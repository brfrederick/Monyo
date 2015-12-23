#pragma once
#include "../Core/IModule.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"

class GraphicsManager : public IModule, public Singleton<GraphicsManager>
{
public:
	GraphicsManager() {};
	~GraphicsManager() {};

	virtual int Init() override;
	virtual int Shutdown() override;

	void Update();
	void Render();
};