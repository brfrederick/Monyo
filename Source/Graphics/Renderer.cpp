#include "Renderer.h"

int Renderer::Init()
{
	Logger::Debug("Renderer::Init");

	if (this->InitGraphicsAPI() != 0)
	{
		Logger::Debug("GraphicsAPI failed to initialize");
		return -1;
	}

	return 0;
}

int Renderer::InitGraphicsAPI()
{
	Logger::Debug("Renderer::InitGraphicsAPI");

	// create a struct to hold information about the swap chain
	DXGI_SWAP_CHAIN_DESC scd;
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

	//	Swap Chain Description
	scd.BufferCount = 1;                                    // one back buffer
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
	scd.BufferDesc.Width = GameWindow::Get().GetWidth();	// set the back buffer width
	scd.BufferDesc.Height = GameWindow::Get().GetHeight();	// set the back buffer height
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // how swap chain is to be used
	scd.OutputWindow = GameWindow::Get().GetHandle();       // the window to be used
	scd.SampleDesc.Count = 4;                               // how many multisamples
	scd.Windowed = TRUE;                                    // windowed/full-screen mode
	scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;		// allow full-screen switching

	//	Create Device and Swap Chain
	D3D11CreateDeviceAndSwapChain(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		NULL,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&scd,
		&m_swapChain,
		&m_device,
		NULL,
		&m_ctx
		);

	// --------------------------


	//	BACK BUFFER 
	ID3D11Texture2D *pBackBuffer;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	// use the back buffer address to create the render target
	m_device->CreateRenderTargetView(pBackBuffer, NULL, &m_backBuffer);
	pBackBuffer->Release();

	// ------------------------
	// DepthStencilDesc
	D3D11_TEXTURE2D_DESC dsd;
	dsd.Width = GameWindow::Get().GetWidth();
	dsd.Height = GameWindow::Get().GetHeight();
	dsd.MipLevels = 1;
	dsd.ArraySize = 1;
	dsd.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	dsd.Usage = D3D11_USAGE_DEFAULT;
	dsd.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	dsd.CPUAccessFlags = 0;
	dsd.MiscFlags = 0;
	dsd.SampleDesc.Count = 1;
	dsd.SampleDesc.Quality = 0;

	m_device->CreateTexture2D(&dsd, 0, &m_depthStencilBuffer);
	m_device->CreateDepthStencilView(m_depthStencilBuffer, 0, &m_depthStencilView);

	// set the render target as the back buffer
	m_ctx->OMSetRenderTargets(1, &m_backBuffer, m_depthStencilView);

	//	View Port
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = GameWindow::Get().GetWidth();
	viewport.Height = GameWindow::Get().GetHeight();

	m_ctx->RSSetViewports(1, &viewport);

	return 0;
}

int Renderer::OnResize()
{
	return 0;
}

int Renderer::Shutdown()
{
	Logger::Debug("Renderer::Shutdown");

	this->ShutdownD3D();

	return 0;
}

int Renderer::ShutdownD3D()
{
	// Exit fullscreen
	m_swapChain->SetFullscreenState(FALSE, NULL);
	m_swapChain->Release();
	m_backBuffer->Release();
	m_device->Release();
	m_ctx->Release();

	return 0;
}

void Renderer::Render()
{
	Clear();

	// Call to render steps
	// GeometryPass
	// LightPass
	// TransparentPass
	// Particle Pass
	// Post Processing Passes
	// UI

	m_swapChain->Present(0, 0);
}

void Renderer::Clear() 
{
	// I like this color.. lets call it MonyoOrange? Oh or MonyoBlue cause reasons.
	float clearColor[4] = { 1.0f, 0.4f, 0.2f, 1.0f };

	m_ctx->ClearRenderTargetView(m_backBuffer, clearColor);
	m_ctx->ClearDepthStencilView(
		m_depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0
	);
}