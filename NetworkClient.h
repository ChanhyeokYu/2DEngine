#pragma once
#include "INetworkNode.h"
#include "TCPSocket.h"
#include <memory>
#include <vector>

class NetworkClient :
    public INetworkNode
{
public:
    NetworkClient();
    virtual ~NetworkClient();

    virtual bool Start(const std::string& address, int port) override;
    virtual void Stop() override;
    virtual void Tick(float DeltaTime) override;

public:
    void SendMessage(const std::string& msg);

private:
    std::shared_ptr<TCPSocket> ClientSocket;
    
};

