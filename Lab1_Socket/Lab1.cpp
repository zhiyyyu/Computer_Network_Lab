// Lab1.cpp: 定义应用程序的入口点。
//

#include "Lab1.h"

using namespace std;

int main()
{
	Config config;
	Server srv;
	if (srv.WinsockStartup() == -1) return -1;
	if (srv.ServerStartup() == -1) return -1;
	if (srv.ListenStartup() == -1) return -1;
	if (srv.Loop() == -1) return -1;
	return 0;

}
