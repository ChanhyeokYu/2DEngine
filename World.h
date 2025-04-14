#pragma once
#include "Actor.h"
#include <vector>
#include <memory>

class GameMode;

class World
{
public:
	void AddActor(std::shared_ptr<Actor> actor);
	void BeginPlay();
	void Tick(float DeltaTime);
	void EndPlay();

	std::shared_ptr<GameMode> GetGameMode() { return GlobalGameMode; }
	void SetGameMode(std::shared_ptr<GameMode> gamemode) { GlobalGameMode = gamemode; }
	void MoveGameMode();

private:
	std::vector<std::shared_ptr<Actor>> Actors;
	std::shared_ptr<GameMode> GlobalGameMode;
};

