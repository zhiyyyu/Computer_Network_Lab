#pragma once
#include <iostream>
#include <winsock2.h>

class WinsockEnv
{
private:
	WinsockEnv() = default;
	~WinsockEnv() = default;
public:
	static int Startup();
};
