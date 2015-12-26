#pragma once
#include <d3d11.h>
#include "../Core/IModule.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"
#include "Renderer.h"

class GraphicsManager : public IModule, public Singleton<GraphicsManager>
{
public:
	GraphicsManager() {};
	~GraphicsManager() {};

	virtual int Init() override;
	virtual int Shutdown() override;

	ID3D11Device* GetDevice() { return m_renderer.GetDevice(); }

	void Update();
	void Render();

private:
	Renderer m_renderer;
};