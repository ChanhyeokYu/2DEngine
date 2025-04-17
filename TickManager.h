#pragma once
#include "ITickable.h"
#include <vector>
#include <memory>

// 각 클래스들의 tick들의 관리를 위한 매니저 클래스

class TickManager
{
public:
	void Register(std::shared_ptr<ITickable> tickable);
	void TickAll(float DeltaTime);

private:
	std::vector<std::shared_ptr<ITickable>> Tickables;

};

