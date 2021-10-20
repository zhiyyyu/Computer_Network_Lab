#pragma once
#include <string>
#include <winsock2.h>
#include <fstream>
#include <cassert>

#include "json/json.h"

using namespace std;

//保存配置信息
class Config
{
public:
	static const int MAX_CONNECTION;		//最大连接数
	static const int BUFFER_LENGTH;			//缓冲区大小
	static string SERVER_ADDRESS;				//服务器地址
	static int PORT;							//服务器端口
	static const u_long BLOCK_MODE;			//SOCKET阻塞模式
	static string ROOT;

	typedef enum MODE {
		Non_Blocking = 0,
		Blocking = 1,
	} MODE;

	Config();
	~Config() = default;

private:
};
