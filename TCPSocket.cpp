#include "TCPSocket.h"
#include <iostream>

TCPSocket::TCPSocket()
{
}

TCPSocket::~TCPSocket()
{
    Shutdown();
}

bool TCPSocket::Initialize()
{
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        std::cerr << "WSAStartup failed with error: " << result << std::endl;
        return false;
    }

    return true;
}

void TCPSocket::Shutdown()
{
    if (Socket_ != INVALID_SOCKET)
    {
        closesocket(Socket_);
        Socket_ = INVALID_SOCKET;
    }
    WSACleanup();
}

bool TCPSocket::BindAndListen(int port)
{
    isServer_ = true;

    Socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (Socket_ == INVALID_SOCKET)
    {
        std::cerr << "Failed to create socket. Error: " << WSAGetLastError() << std::endl;
        return false;
    }

    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = INADDR_ANY;
    service.sin_port = htons(port);

    if (bind(Socket_, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)
    {
        std::cerr << "Bind failed. Error: " << WSAGetLastError() << std::endl;
        closesocket(Socket_);
        Socket_ = INVALID_SOCKET;
        return false;   
    }

    if (listen(Socket_, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cerr << "Listen failed. Error: " << WSAGetLastError() << std::endl;
        closesocket(Socket_);
        Socket_ = INVALID_SOCKET;
        return false;
    }

    std::cout << "Server listening on port" << port << std::endl;
    return false;
}

std::shared_ptr<TCPSocket> TCPSocket::Accpet()
{
    return std::shared_ptr<TCPSocket>();
}

bool TCPSocket::Connect(const std::string& address, int port)
{
    return false;
}

int TCPSocket::Send(const char* data, int length)
{
    return 0;
}

int TCPSocket::Receive(char* buffer, int length)
{
    return 0;
}
