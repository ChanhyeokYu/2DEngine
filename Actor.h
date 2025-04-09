#pragma once

#include <vector>

#include "UObject.h"
#include "ActorComponent.h"
#include "SceneComponent.h"

class Actor : public UObject
{
public:
	Actor();
	virtual ~Actor() = default;

public:
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);
	virtual void EndPlay();

	void AddComponent(std::shared_ptr<ActorComponent> component);

	std::shared_ptr<SceneComponent> GetRootComponent() const { return rootComponent; }

protected:
	std::vector<std::shared_ptr<ActorComponent>> components;
	std::shared_ptr<SceneComponent> rootComponent;

};

