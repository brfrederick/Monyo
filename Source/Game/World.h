#pragma once
#pragma once
#include "../Core/IModule.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"

class World : public IModule, public Singleton<World>
{
public:
	World() {};
	~World() {};

	// For testing purposes
	Model* model;

	virtual int Init() override;
	virtual int Shutdown() override;

	void Update();
	void Render();
};