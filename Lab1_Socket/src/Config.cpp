#include "Config.h"

using namespace std;

string Config::SERVER_ADDRESS = "127.0.0.1";			//服务器IP地址
const int Config::MAX_CONNECTION = 50;					//最大连接数50
const int Config::BUFFER_LENGTH = 1024;					//缓冲区大小1024字节
int Config::PORT = 5050;								//服务器端口5050
const u_long Config::BLOCK_MODE = MODE::Non_Blocking;	//SOCKET为非阻塞模式
string Config::ROOT = "";

Config::Config() {
	std::ifstream confg_file;
	confg_file.open("../../../utils/init.json");
	assert(confg_file.is_open());

	Json::Reader reader;
	Json::Value root;
	// 解析到root，root将包含Json里所有子元素
	if (!reader.parse(confg_file, root, false))
	{
		cerr << "parse failed \n";
		return;
	}
	Config::SERVER_ADDRESS = root["ip"].asString();
	Config::PORT = root["port"].asInt();
	Config::ROOT = root["root"].asString();
}