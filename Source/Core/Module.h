#pragma once
#include "../Util/Singleton.h"

class Module
{
public:
	virtual int Init() = 0;
	virtual int Shutdown() = 0;
};
