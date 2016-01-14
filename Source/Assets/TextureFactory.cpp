#include "../Core/GameWindow.h"
#include "../Graphics/GraphicsManager.h"
#include "TextureFactory.h"

ID3D11Texture2D* TextureFactory::LoadTexture(std::string fileName)
{
	ID3D11Texture2D* texture;

	D3D11_TEXTURE2D_DESC textureDesc;
	textureDesc.ArraySize = 1;
	textureDesc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
	textureDesc.CPUAccessFlags = 0;
	textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	textureDesc.Height = GameWindow::Get().GetWidth();
	textureDesc.MipLevels = 1;
	textureDesc.MiscFlags = 0;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.SampleDesc.Quality = 0;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.Width = GameWindow::Get().GetHeight();

	GraphicsManager::Get().GetDevice()->CreateTexture2D(&textureDesc, 0, &texture);
	
	return texture;
}