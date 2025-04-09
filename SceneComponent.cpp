#include "SceneComponent.h"

SceneComponent::SceneComponent()
    : Position{ 0.0f, 0.0f }, Rotation(0.0f), Scale{ 0.0f, 0.0f }
{
}

void SceneComponent::SetPosition(float x, float y)
{
    Position.X = x;
    Position.Y = y; 
}

void SceneComponent::SetRotation(float degrees)
{
    Rotation = degrees;
}

void SceneComponent::SetScale(float x, float y)
{
    Scale.X = x;    
    Scale.Y = y;   
}

Vector2 SceneComponent::GetPosition() const
{
    return Position;
}

float SceneComponent::GetRotation() const
{
    return Rotation;
}

Vector2 SceneComponent::GetScale() const
{
    return Scale;
}

void SceneComponent::AttachTo(std::shared_ptr<SceneComponent> parent)
{
    Parent = parent;
    parent->AddChild(shared_from_this());
}

void SceneComponent::AddChild(std::shared_ptr<SceneComponent> child)
{
    Children.push_back(child);
}

const std::vector<std::shared_ptr<SceneComponent>>& SceneComponent::GetChildren() const
{
    return Children;
}

