#pragma once
#include "ITickable.h"
#include <vector>
#include <memory>

class TickManager
{
public:
	void Register(std::shared_ptr<ITickable> tickable);
	void TickAll(float DeltaTime);

private:
	std::vector<std::shared_ptr<ITickable>> Tickables;

};

