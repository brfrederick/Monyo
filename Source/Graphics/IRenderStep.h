#pragma once
#include "GraphicsManager.h"
#include  <DirectXHelpers.h>

class IRenderStep 
{

public:	
	virtual void Render() = 0;	// Render

protected:
	virtual void Pre() = 0;		// Change settings
	virtual void Post() = 0;	// Reset settings
};