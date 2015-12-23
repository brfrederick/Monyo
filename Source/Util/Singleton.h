#pragma once

template <typename T>
class Singleton 
{

public:
	static T& Get() 
	{
		static T instance;
		return instance;
	}

protected:
	explicit Singleton<T>() {};

};