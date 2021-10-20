#pragma once
#include <winsock2.h>
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <regex>

#include "Winsock.h"
#include "Config.h"

using namespace std;

typedef int STATUS;

typedef enum {
	HTML,
	IMAGE,
} FILETYPE;

//服务器
class Server
{
private:
	// 监听socket
	SOCKET listening_socket;
	// server address
	sockaddr_in server_addr;

	//fd_set rfds;				//用于检查socket是否有数据到来的的文件描述符，用于socket非阻塞模式下等待网络事件通知（有数据到来）
	//fd_set wfds;				//用于检查socket是否可以发送的文件描述符，用于socket非阻塞模式下等待网络事件通知（可以发送数据）

	string LF = "\r\n";
	string root = "C:\\Users\\acer\\source\\repos\\Lab1\\utils";

protected:
	

public:
	Server();
	~Server();
	int WinsockStartup();		//初始化Winsock
	int ServerStartup();		//初始化Server，包括创建SOCKET，绑定到IP和PORT
	int ListenStartup();		//开始监听客户端请求
	int Loop();					//循环执行"等待客户端请求"->“向其他客户转发信息”->"等待客户端消息"
};

class Client {
public:
	// 会话Socket
	SOCKET session_socket;
	// client address
	sockaddr_in client_addr;

	// client session
	void session(SOCKET );

	Client();
	~Client();

private:

	string LF = "\r\n";
	string OK = "HTTP/1.1 200 OK" + LF;
	string NOTFOUND = "HTTP/1.1 404 Not Found" + LF;
	string BADREQ = "HTTP/1.1 400 Bad Request" + LF;
	
	ifstream file_to_send;
	/*
	regex reg_file_name;
	regex reg_file_type;

	string msg_get;
	string msg_url;

	smatch req_msg;
	smatch filetype;
	*/

	char* buf;
	char* data_to_send;

	string getHeaderLine(const string& content_type, int content_length);
	int getFileLength(ifstream& file);
};