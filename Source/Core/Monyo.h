#pragma once
#include "Module.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"
#include "../Graphics/GraphicsManager.h"
#include "../Game/World.h"
#include "../Assets/AssetManager.h"

class Monyo : public Module, public Singleton<Monyo>
{

public:

	virtual int Init() override;
	virtual int Shutdown() override;
	
	void Update();
	void Render();
};