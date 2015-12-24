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

	// clear out the struct for use
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

	//	Swap Chain Description
	scd.BufferCount = 1;                                    // one back buffer
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
	scd.BufferDesc.Width = 800;//GameWindow::Get().GetWidth();	// set the back buffer width
	scd.BufferDesc.Height = 600; //GameWindow::Get().GetHeight();	// set the back buffer height
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

	//	BACK BUFFER 
	ID3D11Texture2D *pBackBuffer;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	// use the back buffer address to create the render target
	m_device->CreateRenderTargetView(pBackBuffer, NULL, &m_backBuffer);
	pBackBuffer->Release();

	// set the render target as the back buffer
	m_ctx->OMSetRenderTargets(1, &m_backBuffer, NULL);

	//	View Port
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = 800;//GameWindow::Get().GetWidth();
	viewport.Height = 600;//GameWindow::Get().GetHeight();

	m_ctx->RSSetViewports(1, &viewport);

	return 0;
}

int Renderer::OnResize()
{
	/*
	#pragma region Shaders
	//----------------------------------//
	//	Shaders
	//----------------------------------//
	ID3D10Blob *vsBlob, *psBlob;
	D3DReadFileToBlob(L"VertexShader.cso", &vsBlob);
	D3DReadFileToBlob(L"PixelShader.cso", &psBlob);

	// Vertex Shader
	device->CreateVertexShader(
	vsBlob->GetBufferPointer(),
	vsBlob->GetBufferSize(),
	NULL,
	&pVertexShader
	);
	devctx->VSSetShader(pVertexShader, 0, 0);

	// Pixel Shader
	device->CreatePixelShader(
	psBlob->GetBufferPointer(),
	psBlob->GetBufferSize(),
	NULL,
	&pPixelShader
	);
	devctx->PSSetShader(pPixelShader, 0, 0);

	#pragma endregion Create and set Pixel and Vertex shaders


	#pragma region Vertex_Buffer
	//----------------------------------//
	//	Vertex Buffer
	//----------------------------------//
	D3D11_BUFFER_DESC bufferDesc;
	ZeroMemory(&bufferDesc, sizeof(bufferDesc));

	bufferDesc.Usage = D3D11_USAGE_DYNAMIC;							// write access access by CPU and GPU
	bufferDesc.ByteWidth = sizeof(VERTEX) * 3;						// size is the VERTEX struct * 3
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;				// use as a vertex buffer
	bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;				// allow CPU to write in buffer

	device->CreateBuffer(&bufferDesc, NULL, &pVertexBuffer);        // create the buffer

	// create a triangle using the VERTEX struct

	VERTEX OurVertices[] =
	{
	{ 0.0f, 0.5f, 0.0f,{ 1.0f, 0.0f, 0.0f, 1.0f } },
	{ 0.45f, -0.5, 0.0f,{ 0.0f, 1.0f, 0.0f, 1.0f } },
	{ -0.45f, -0.5f, 0.0f,{ 0.0f, 0.0f, 1.0f, 1.0f } }
	};

	// copy the vertices into the buffer
	D3D11_MAPPED_SUBRESOURCE ms;
	devctx->Map(pVertexBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &ms);		// map the buffer
	memcpy(ms.pData, OurVertices, sizeof(OurVertices));							// copy the data
	devctx->Unmap(pVertexBuffer, NULL);
	// unmap the buffer
	#pragma endregion

	#pragma region Input_Layout
	//----------------------------------//
	//	Input Layout
	//----------------------------------//

	// Define Input Layout
	D3D11_INPUT_ELEMENT_DESC inputElementDesc[] =
	{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	// Create Input Layout
	device->CreateInputLayout(
	inputElementDesc,
	2,
	vsBlob->GetBufferPointer(),
	vsBlob->GetBufferSize(),
	&pInputLayout
	);

	// Set Input Layout
	devctx->IASetInputLayout(pInputLayout);
	#pragma endregion Create and set the Input Layout
	*/
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

	//pVertexShader->Release();
	//pPixelShader->Release();

	m_swapChain->Release();
	m_backBuffer->Release();
	m_device->Release();
	m_ctx->Release();

	return 0;
}

void Renderer::Render()
{
	// Clear backBuffer
	float clearColor[4] = { 0.0f, 0.2f, 0.4f, 1.0f };
	m_ctx->ClearRenderTargetView(m_backBuffer, clearColor);

	// Render to back buffer here
	// select which vertex buffer to display
	//UINT stride = sizeof(VERTEX);
	//UINT offset = 0;
	//devctx->IASetVertexBuffers(0, 1, &pVertexBuffer, &stride, &offset);

	// select which primtive type we are using
	//m_ctx->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// draw the vertex buffer to the back buffer
	//m_ctx->Draw(0, 0);

	// switch the back buffer and the front buffer
	m_swapChain->Present(0, 0);
}