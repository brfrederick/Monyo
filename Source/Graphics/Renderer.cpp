#include "Renderer.h"

int Renderer::Init()
{
	Logger::Debug("Renderer::Init");

	if (this->InitGraphicsAPI() != 0)
	{
		Logger::Debug("GraphicsAPI failed to initialize");
		return -1;
	}

	if (this->InitPipeline() != 0)
	{
		Logger::Debug("Graphics Pipeline failed to initialize");
		return -1;
	}
	
	return 0;
}

int Renderer::InitGraphicsAPI()
{

	return 0;
}

int Renderer::InitPipeline()
{

	return 0;
}

int Renderer::Shutdown()
{
	Logger::Debug("Renderer::Init");
	return 0;
}

void Renderer::Render()
{

}