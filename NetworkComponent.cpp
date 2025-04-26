#include "NetworkComponent.h"
#include "TCPSocket.h"
#include <iostream>

NetworkComponent::NetworkComponent(std::shared_ptr<TCPSocket> socket)
	:Socket(socket)
{
}

void NetworkComponent::SendMessageNet(const std::string& message)
{
	if (!Socket)
	{
		return;
	}

	Packet packet(message);
	Socket->Send(packet.Data(), packet.Size());

}

void NetworkComponent::Initialize()
{
}

void NetworkComponent::Update(float DeltaTime)
{
	if (!Socket)
	{
		return;
	}

	char buffer[512];
	int recevied = Socket->Receive(buffer, sizeof(buffer));
	if (recevied > 0)
	{
		Packet packet(std::string(buffer, recevied));
		std::cout << "[NetworkComponent] Received: " << packet.ToString() << std::endl;
	}

}
