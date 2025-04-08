#pragma once
#include "Actor.h"
#include <vector>
#include <memory>

class World
{
public:
	void AddActor(std::shared_ptr<Actor> actor);
	void BeginPlay();
	void Tick(float DeltaTime);
	void EndPlay();

private:
	std::vector<std::shared_ptr<Actor>> Actors;
};

