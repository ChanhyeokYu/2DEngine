#pragma once
#include "INetworkNode.h"
#include "TCPSocket.h"
#include <vector>
#include <memory>

class NetworkServer : public INetworkNode
{
public:
	NetworkServer();
	virtual ~NetworkServer();

public:
	virtual bool Start(const std::string& address, int port) override;
	virtual void Stop() override;
	virtual void Tick(float DaltaTime) override;

private:
	std::shared_ptr<TCPSocket> ListenSocket;
	std::vector<std::shared_ptr<TCPSocket>> ClientSockets;

};

