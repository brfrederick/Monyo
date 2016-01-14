#pragma once
#include <d3d11.h>
#include <string>

class TextureFactory
{
public:
	static ID3D11Texture2D* LoadTexture(std::string fileName);
};