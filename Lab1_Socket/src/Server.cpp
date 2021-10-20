#pragma once
#include "Server.h"
#pragma comment(lib, "Ws2_32.lib")

#pragma warning(disable:4996)

using namespace std;

Server::Server()
{
	
}

Server::~Server()
{
	WSACleanup(); //清理winsock 运行环境
}

//初始化Winsock
int Server::WinsockStartup() {
	if (WinsockEnv::Startup() == -1) return -1;	//初始化Winsock
	return 0;
}

//初始化Server，包括创建sockect，绑定到IP和PORT
int Server::ServerStartup() {
	//创建 TCP socket
	this->listening_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->listening_socket == INVALID_SOCKET) {
		cout << "Server socket creare error !\n";
		WSACleanup();
		return -1;
	}
	cout << "Server socket create ok!\n";

	//设置服务器IP地址和端口号
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(Config::PORT);
	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//会自动找到服务器合适的IP地址
//	server_addr.sin_addr.S_un.S_addr = inet_addr(Config::SERVERADDRESS.c_str()); //这是另外一种设置IP地址的方法

	//绑定监听socket和server addr
	int rtn = bind(this->listening_socket, (LPSOCKADDR) & (server_addr), sizeof(server_addr));
	if (rtn == SOCKET_ERROR) {
		cout << "Server socket bind error!\n";
		closesocket(this->listening_socket);
		WSACleanup();
		return -1;
	}

	cout << "Server socket bind ok!\n";
	return 0;
}

//开始监听,等待客户的连接请求
int Server::ListenStartup() {
	int rtn = listen(this->listening_socket, Config::MAX_CONNECTION);
	if (rtn == SOCKET_ERROR) {
		cout << "Server socket listen error!\n";
		closesocket(this->listening_socket);
		WSACleanup();
		return -1;
	}

	cout << "Server socket listen ok!\n";
	return 0;
}


//接受客户端发来的请求和数据并转发
int Server::Loop() {
	u_long blockMode = Config::BLOCK_MODE;//将srvSock设为非阻塞模式以监听客户连接请求
	int rtn;

	if ((rtn = ioctlsocket(this->listening_socket, FIONBIO, &blockMode) == SOCKET_ERROR)) { //FIONBIO：允许或禁止套接口s的非阻塞模式。
		cout << "ioctlsocket() failed with error!\n";
		return -1;
	}
	cout << "ioctlsocket() for server socket ok! Waiting for client connection and data\n";

	int sockerror;
	int length = sizeof(sockaddr);

	while (true) { //等待客户的连接请求

		Client client;
		client.session_socket = accept(listening_socket, (sockaddr*)&client.client_addr, &length);

		if (client.session_socket == INVALID_SOCKET) {
			cout << "accept error" << endl;
			sockerror = WSAGetLastError();
			return 0;
		}
		else {
			cout << "accept success" << endl;
			thread response_thread(&Client::session, &client, client.session_socket);//开启一个新的线程来处理这一个客户的请求
			cout << "request IP:" << (int)client.client_addr.sin_addr.S_un.S_un_b.s_b1 << "." << (int)client.client_addr.sin_addr.S_un.S_un_b.s_b2 << "." << (int)client.client_addr.sin_addr.S_un.S_un_b.s_b3 << "." << (int)client.client_addr.sin_addr.S_un.S_un_b.s_b4 << endl;
			cout << "request Port:" << client.client_addr.sin_port << endl;
			response_thread.detach();
		}
	}

	return 0;
}

Client::Client() {
	buf = (char*)malloc(sizeof(char) * Config::BUFFER_LENGTH);
	// data_to_send = (char*)malloc(sizeof(char) * Config::BUFFER_LENGTH);
}

Client::~Client() {
	free(buf);
	// free(data_to_send);
}

string Client::getHeaderLine(const string& content_type, int content_length) {
	static vector<string> header_line = {
		"Connection: ",
		"Date: ",
		"Server: ",
		"Last-Modified: ",
		"Content-Length: ",
		"Content-Type: "
	};
	string s = header_line[0] + string("keep-alive") + LF +
		//header_line[1] + string("") + LF +
		header_line[2] + string("Mozilla/5.0") + LF +
		//header_line[3] + string("") + LF +
		header_line[4] + to_string(content_length) + LF +
		header_line[5] + content_type + LF + LF;
	return s;
}

void Client::session(SOCKET session_socket) {

	STATUS status = recv(session_socket, buf, Config::BUFFER_LENGTH, 0);
	if (status == SOCKET_ERROR) {
		status = WSAGetLastError();
		cout << "thread falied!" << endl;
		return;
	}
	// 请求报文
	string request_msg(buf);
	cout << request_msg << endl;
	// 对接受到的消息进行解析
	smatch strmatch;//正则表达式结果文本
	// 匹配请求行
	regex reg_file_name("([A-Za-z]+)+ (.*)+ (HTTP/[0-9][.][0-9])");
	
	int matchnum = regex_search(request_msg, strmatch, reg_file_name);

	if (matchnum == 0) {
		cout << "request message exception" << endl;
		int sendre = send(session_socket, BADREQ.c_str(), BADREQ.length(), 0);
		file_to_send = ifstream(Config::ROOT + "/400.html", ios::binary);
		closesocket(session_socket);
		return;
	}
	string msg_get = strmatch[1];
	string msg_url = strmatch[2];
	smatch filetype;
	regex reg_file_type("([.].*)$");
	matchnum = regex_search(msg_url, filetype, reg_file_type);
	if (matchnum == 0) {
		cout << msg_get + msg_url + "FORMAT ERROR" << endl;
		int sendre = send(session_socket, NOTFOUND.c_str(), NOTFOUND.length(), 0);
		closesocket(session_socket);
		return;
	}

	file_to_send = ifstream(Config::ROOT + msg_url, ios::binary);
	if (!file_to_send.is_open()) {
		cout << msg_url + "NOT FOUND" << endl;
		int sendre = send(session_socket, NOTFOUND.c_str(), NOTFOUND.length(),0);
		file_to_send = ifstream(Config::ROOT + "/404.html", ios::binary);
	}
add_data_and_send:

	cout << file_to_send.rdbuf() << endl;
	filebuf* file_buf = file_to_send.rdbuf();
	int file_size = file_buf->pubseekoff(0, file_to_send.end, file_to_send.in);
	file_buf->pubseekpos(0, file_to_send.in);
	if (file_size <= 0) {
		cout << "load file into memory failed!" << endl;
		int sendre = send(session_socket, NOTFOUND.c_str(), NOTFOUND.length(), 0);
		closesocket(session_socket);
		return;
	}
	data_to_send = new char[file_size];
	char* tail = data_to_send + file_size;
	file_buf->sgetn(data_to_send, file_size);
	/*
	int file_size = getFileLength(file_to_send);
	data_to_send = (char*)malloc(sizeof(char) * file_size);
	file_to_send.read(data_to_send, file_size);
	*/
	file_to_send.close();
	
	string content_type = filetype[1] == ".jpg" ? "image/jpeg" : "text/html";
	cout << "file type: " << filetype[1] << endl;
	cout << "success return file " + msg_url << endl;
	string header_line = getHeaderLine(content_type, file_size);
	string response_head = OK + header_line;
	cout << response_head << endl;
	cout << data_to_send << endl;
	int send_num = send(session_socket, response_head.c_str(), response_head.length(), 0);
	char* p = data_to_send;
	while (file_size) {
		send_num = send(session_socket, p, file_size, 0);
		p += send_num;
		file_size -= send_num;
	}
	free(data_to_send);
	closesocket(session_socket);
	return;
}


int Client::getFileLength(ifstream& file) {
	streampos head = file.tellg();
	file.seekg(0, ios::end);
	int size = file.tellg();
	file.seekg(head);
	return size;
}