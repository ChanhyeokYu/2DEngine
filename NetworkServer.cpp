#include "NetworkServer.h"
#include <iostream>

NetworkServer::NetworkServer()
{
}

NetworkServer::~NetworkServer()
{
    Stop();
}

bool NetworkServer::Start(const std::string& address, int port)
{
    ListenSocket = std::make_shared<TCPSocket>();
    if (!ListenSocket)
    {
        std::cerr << "Failed to initialize ListenSocket." << std::endl; 
        return false;
    }

    if (!ListenSocket->BindAndListen(port))
    {
        std::cerr << "Failed to bind and listen on port: " << port << std::endl;   
    }

    std::cerr << "NetworkServer started on port: " << port << std::endl;
    return true;
}

void NetworkServer::Stop()
{
    for (auto& client : ClientSockets )
    {
        if (client)
        {
            client->Shutdown();
        }
    }
    ClientSockets.clear();

    if (ListenSocket)
    {
        ListenSocket->Shutdown();
        ListenSocket.reset();
    }

    std::cout << "NetworkServer stopped" << std::endl;
}

void NetworkServer::Tick(float DaltaTime)
{
    if (ListenSocket)
    {
        auto newClient = ListenSocket->Accpet();
        if (newClient)
        {
            ClientSockets.push_back(newClient);
            std::cout << "New client connected. Total: " << ClientSockets.size() << std::endl;
        }
    }

    char buffer[512];
    for (auto& client : ClientSockets)
    {
        if (!client)
        {
            continue;
        }

        int received = client->Receive(buffer, sizeof(buffer));
        if (received > 0)
        {
            std::string msg(buffer, received);
            std::cout << "Received: " << msg << std::endl;

            client->Send(msg.c_str(), msg.size());
        }
    }
}
