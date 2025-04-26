#include <iostream>
#include "Engine.h"
#include "Actor.h"
#include "NetworkComponent.h"
#include "TCPSocket.h"

void Engine::Initialize()
{
	MainWorld = std::make_shared<World>();
	MainGameMode = std::make_shared<GameMode>();
	MainGameMode->InitGame(MainWorld);

	MainTickManager.Register(std::static_pointer_cast<ITickable>(MainWorld));
	MainTickManager.Register(std::static_pointer_cast<ITickable>(MainGameMode));

	auto clientSocket = std::make_shared<TCPSocket>();
	if (!clientSocket->Initialize())
	{
		std::cerr << "Failed to connect to server." << std::endl;
		return;
	}

	if (clientSocket->Connect("127.0.0.1", 7777))
	{
		std::cerr << "Failed to connect to server." << std::endl;
		return;
	}

	auto networkComp = std::make_shared<NetworkComponent>(clientSocket);
	Actor player;

	player.AddComponent(networkComp);
}

void Engine::Tick(float DeltaTime)
{
	MainTickManager.TickAll(DeltaTime);
}

void Engine::Shutdown()
{
	bIsRunning = false;
	MainWorld->EndPlay();
}

bool Engine::IsRunning()
{
	return bIsRunning;
}
