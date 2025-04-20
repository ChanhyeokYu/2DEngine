#pragma once
#define WIND32_LEAN_AND_MEAN

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>
#include <memory>

#pragma comment(lib, "ws2_32.lib")

class TCPSocket
{
public:
	TCPSocket();
	~TCPSocket();

	bool Initialize();
	void Shutdown();

	bool BindAndListen(int port);
	std::shared_ptr<TCPSocket> Accpet();
	bool Connect(const std::string& address, int port);

	int Send(const char* data, int length);
	int Receive(char* buffer, int length);

	SOCKET GetSocket() const { return Socket_; }

private:
	SOCKET Socket_ = INVALID_SOCKET;
	bool isServer_ = false;

};

