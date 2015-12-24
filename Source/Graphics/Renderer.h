#pragma once
#include "../Core/IModule.h"
#include "../Core/GameWindow.h"
#include "../Util/Logger.h"
#include <d3d11.h>
#include <d3dcompiler.h>

#if defined(DEBUG) | defined(_DEBUG)
#ifndef HR
#define HR(x)												\
	{															\
		HRESULT hr = (x);										\
		if(FAILED(hr))											\
		{														\
			DXTrace(__FILEW__, (DWORD)__LINE__, hr, L#x, true);	\
			PostQuitMessage(0);									\
		}														\
	}														
#endif
#else
#ifndef HR
#define HR(x) (x) // Do nothing special!
#endif
#endif

class Renderer : public IModule
{

public:
	Renderer() {};
	~Renderer() {};

	virtual int Init() override;
	virtual int Shutdown() override;
	int ShutdownD3D();

	int InitGraphicsAPI();
	int OnResize();
	void Render();

protected:
	ID3D11Device*             m_device;
	ID3D11DeviceContext*      m_ctx;
	IDXGISwapChain*           m_swapChain;
	ID3D11Texture2D*          m_depthStencilBuffer;
	ID3D11RenderTargetView*   m_backBuffer;
	ID3D11DepthStencilView*   m_depthStencilView;
};
