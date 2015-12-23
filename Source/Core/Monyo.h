#pragma once
#include "IModule.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"
#include "../Graphics/GraphicsManager.h"
#include "../Game/World.h"
#include "../Assets/AssetManager.h"
#include "GameWindow.h"

class Monyo : public IModule, public Singleton<Monyo>
{

public:

	virtual int Init() override;
	virtual int Shutdown() override;
	
	// Loop
	void Update();
	void Render();

	// Window
	void ShowWindow();
	void UpdateWindow();
};