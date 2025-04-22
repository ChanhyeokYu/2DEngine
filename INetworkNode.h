#pragma once
#include <string>

class INetworkNode
{
public:
	virtual ~INetworkNode() = default;

	virtual bool Start(const std::string& address, int port) = 0;
	virtual void Stop() = 0;
	virtual void Tick(float DeltaTime) = 0;

};

