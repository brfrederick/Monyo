#pragma once
#pragma once
#include "../Core/Module.h"
#include "../Util/Singleton.h"
#include "../Util/Logger.h"

class World : public Module, public Singleton<World>
{
public:
	World() {};
	~World() {};

	virtual int Init() override;
	virtual int Shutdown() override;

	void Update();
	void Render();
};