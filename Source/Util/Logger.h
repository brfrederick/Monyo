#pragma once
#include <string>
#include <Windows.h>

class Logger
{
public:

	static void Debug(std::string str) {
		str = "Debug: " + str + '\n';

		// Convert string to a LPCWSTR 
		std::wstring stemp = std::wstring(str.begin(), str.end());
		LPCWSTR msg = stemp.c_str();
		OutputDebugString(msg);
	}
};