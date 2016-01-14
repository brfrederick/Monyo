#pragma once
#include <d3d11.h>
#include <vector>
#include "../Core/IModule.h"
#include "../Assets/Model.h"
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
	ID3D11DeviceContext* GetContext() { return m_renderer.GetContext(); }

	void Update();
	void Render();
	void RegisterModel(Model*);
	void DeregisterModel(Model*);
	std::vector<Model*> GetModels();

private:
	Renderer m_renderer;
	std::vector<Model*> m_models;
};