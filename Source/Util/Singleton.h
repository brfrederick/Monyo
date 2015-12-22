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

private:
	Singleton<T>() {};
	Singleton<T>(Singleton<T> const&);
	void operator=(Singleton<T> const&) = {};

public:
	Singleton<T>(Singleton<T> const&) = delete;
	void operator=(Singleton<T> const&) = delete;

};