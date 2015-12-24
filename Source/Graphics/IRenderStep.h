#pragma once
#include "GraphicsManager.h"
#include  <DirectXHelpers.h>

class IRenderStep 
{
	virtual void Render() = 0;
};