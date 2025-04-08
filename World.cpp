#include "World.h"

void World::AddActor(std::shared_ptr<Actor> actor)
{
	Actors.push_back(actor);
}

void World::BeginPlay()
{
	for (auto& actor : Actors)
	{
		actor->BeginPlay();
	}
}

void World::Tick(float DeltaTime)
{
	for (auto& actor : Actors)
	{
		actor->Tick(DeltaTime);
	}
}

void World::EndPlay()
{
	for (auto& actor : Actors)
	{
		actor->EndPlay();
	}
}
