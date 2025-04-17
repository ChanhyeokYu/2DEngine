#include "TCPSocket.h"

TCPSocket::TCPSocket()
{
}

TCPSocket::~TCPSocket()
{
}

bool TCPSocket::Initialize()
{
    return false;
}

void TCPSocket::Shotdown()
{
}

bool TCPSocket::BindAndListen(int port)
{
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
