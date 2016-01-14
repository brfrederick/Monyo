#pragma once
#include <string>
//#include "../Graphics/GraphicsManager.h"
#include "Shader.h"

class ShaderFactory 
{
public:
	static SimpleVertexShader* LoadVertexShader(std::string file);
	static SimplePixelShader* LoadPixelShader(std::string file);
	static SimpleGeometryShader* LoadGeometryShader(std::string file);
};