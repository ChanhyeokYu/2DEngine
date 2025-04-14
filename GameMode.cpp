#include "GameMode.h"
#include "World.h"
#include "PlayerController.h"
#include "Pawn.h"

void GameMode::InitGame(std::shared_ptr<World> world)
{
	auto player = std::make_shared<Pawn>();
	world->AddActor(player);

	MainPlayerController = std::make_shared<PlayerController>();
	MainPlayerController->Possess(player);

}

