#pragma once
#include "UObject.h"
#include "ActorComponent.h"
#include <vector>

class Actor : public UObject
{
public:
	Actor() = default;
	virtual ~Actor() = default;

public:
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);
	virtual void EndPlay();

	void AddComponent(std::shared_ptr<ActorComponent> component);

protected:
	std::vector<std::shared_ptr<ActorComponent>> components;

};

