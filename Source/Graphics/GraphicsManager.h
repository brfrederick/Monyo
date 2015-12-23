#pragma once
#include "../Core/Module.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"

class GraphicsManager : public Module, public Singleton<GraphicsManager>
{
public:
	GraphicsManager() {};
	~GraphicsManager() {};

	virtual int Init() override;
	virtual int Shutdown() override;

	void Update();
	void Render();
};