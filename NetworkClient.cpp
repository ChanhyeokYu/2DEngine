#include "NetworkClient.h"
#include <iostream>

NetworkClient::NetworkClient()
{
}

NetworkClient::~NetworkClient()
{
    Stop();
}

bool NetworkClient::Start(const std::string& address, int port)
{
    ClientSocket = std::make_shared<TCPSocket>();
    if (!ClientSocket)
    {
        std::cerr << "Failed to initialize client socket." << std::endl;
        return false;
    }

    if (!ClientSocket->Connect(address, port))
    {
        std::cerr << "Failed to connect to server." << std::endl;
        return false;
    }

    std::cout << "Connect to server: " << address << " : " << port << std::endl;
    return false;
}

void NetworkClient::Stop()
{
    if (ClientSocket)
    {
        ClientSocket->Shutdown();
        ClientSocket.reset();
    }
    std::cout << "Disconnected from server." << std::endl;
}

void NetworkClient::Tick(float DeltaTime)
{
    if (!ClientSocket)
    {
        return;
    }

    char buffer[512];
    int received = ClientSocket->Receive(buffer, sizeof(buffer));
    if (received > 0)
    {
        std::string msg(buffer, received);
        std::cout << "Server: " << msg << std::endl;
    }
}

void NetworkClient::SendMessage(const std::string& msg)
{
    if (!ClientSocket)
    {
        return;
    }
    ClientSocket->Send(msg.c_str(), msg.size());
}
