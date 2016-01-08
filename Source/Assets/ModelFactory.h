#pragma once
#include <string.h>
#include <fstream>
#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>
#include "../Graphics/GraphicsManager.h"
#include "Model.h"
#include "Vertex.h"

class ModelFactory 
{
public:
	static Model* BuildModel(std::string fileName);
};