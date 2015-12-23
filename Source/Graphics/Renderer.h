#pragma once
#include "../Core/IModule.h"
#include "../Util/Logger.h"
#include <d3d11.h>

class Renderer : public IModule
{

public:
	Renderer() {};
	~Renderer() {};

	virtual int Init() override;
	virtual int Shutdown() override;

	int InitGraphicsAPI();
	int InitPipeline();
	void Render();
};