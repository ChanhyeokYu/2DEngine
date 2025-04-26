#include "NetworkClient.h"
#include <iostream>
#include "Packet.h"

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
        Packet packet(std::string( buffer, received));
        std::cout << "Server: " << packet.ToString()<< std::endl;
    }
}

void NetworkClient::SendMessage(const std::string& msg)
{
    if (!ClientSocket)
    {
        return;
    }
    Packet packet("Hello");
    ClientSocket->Send(packet.Data(), packet.Size());
}
