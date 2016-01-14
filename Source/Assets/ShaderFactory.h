#pragma once
#include <string>
#include "Shader.h"

class ShaderFactory 
{
	ShaderFactory();
	~ShaderFactory();

	SimpleVertexShader* LoadVertexShader(std::string file);
	SimplePixelShader* LoadPixelShader(std::string file);
	SimpleGeometryShader* LoadGeometryShader(std::string file);
};