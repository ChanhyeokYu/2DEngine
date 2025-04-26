#pragma once
#include "Packet.h"
#include "ActorComponent.h"
#include <string>	
#include <memory>

class TCPSocket;

class NetworkComponent : public ActorComponent
{
public:
	NetworkComponent(std::shared_ptr<TCPSocket> socket);

	virtual void Initialize() override;
	virtual void Update(float DeltaTime) override;

	void SendMessageNet(const std::string& message);
	

private:
	std::shared_ptr<TCPSocket> Socket;

};

