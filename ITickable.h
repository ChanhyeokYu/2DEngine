#pragma once
class ITickable
{
public:
	virtual ~ITickable() = default;
	virtual void Tick(float DeltaTime) = 0;
};