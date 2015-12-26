#pragma once
#include "../Core/IModule.h"
#include "../Core/GameWindow.h"
#include "../Util/Logger.h"
#include <d3d11.h>
#include <d3dcompiler.h>

class Renderer : public IModule
{

public:
	Renderer() {};
	~Renderer() {};

	virtual int Init() override;
	int InitGraphicsAPI();
	virtual int Shutdown() override;
	int ShutdownD3D();

	ID3D11Device* GetDevice() { return m_device; }

	int OnResize();
	void Render();
	void Clear();

protected:

	// Directx Variables
	ID3D11Device*             m_device;
	ID3D11DeviceContext*      m_ctx;
	IDXGISwapChain*           m_swapChain;
	ID3D11Texture2D*          m_depthStencilBuffer;
	ID3D11RenderTargetView*   m_backBuffer;
	ID3D11DepthStencilView*   m_depthStencilView;
};
