#pragma once
#include "../Util/Logger.h"
#include "../Util/Singleton.h"
#include <Windows.h>

class InputManager : public Singleton<InputManager>
{
public:
	int ProcessInput(UINT msg);
};
