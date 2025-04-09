#include "Actor.h"

Actor::Actor()
{
	rootComponent = std::make_shared<SceneComponent>();
	components.push_back(rootComponent);
}

void Actor::BeginPlay()
{
	for (auto& comp : components)
	{
		comp->Initialize();
	}
}

void Actor::Tick(float DeltaTime)
{
	for (auto& comp : components)
	{
		comp->Update(DeltaTime);
	}
}

void Actor::EndPlay()
{
	components.clear();
}

void Actor::AddComponent(std::shared_ptr<ActorComponent> component)
{
	components.push_back(component);
}
