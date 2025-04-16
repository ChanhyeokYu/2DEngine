#include "TickManager.h"

void TickManager::Register(std::shared_ptr<ITickable> tickable)
{
	Tickables.push_back(tickable);
}

void TickManager::TickAll(float DeltaTime)
{
	for (auto& tickable : Tickables)
	{
		if (tickable)
		{
			tickable->Tick(DeltaTime);
		}
	}
}
