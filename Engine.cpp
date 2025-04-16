#include "Engine.h"

void Engine::Initialize()
{
	MainWorld = std::make_shared<World>();
	MainGameMode = std::make_shared<GameMode>();
	MainGameMode->InitGame(MainWorld);

	MainTickManager.Register(std::static_pointer_cast<ITickable>(MainWorld));
	MainTickManager.Register(std::static_pointer_cast<ITickable>(MainGameMode));
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
