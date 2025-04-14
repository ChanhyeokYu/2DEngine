#pragma once
#include "ActorComponent.h"
#include <vector>

// 화면 위치(좌표)를 가지고 있을 공간 개념의 컴포넌트
// 공간을 개념으로 그 위에 물체를 세우기 때문에 가장 최우선 뿌리가 됨

struct Vector2
{
    float X = 0.0f;
    float Y = 0.0f;
};

class SceneComponent :
    public ActorComponent, public std::enable_shared_from_this<SceneComponent>
{
public:
    SceneComponent();

    void SetPosition(float x, float y);
    void SetRotation(float degrees);
    void SetScale(float x, float y);

    Vector2 GetPosition() const;
    float GetRotation() const;
    Vector2 GetScale() const;

    void AttachTo(std::shared_ptr<SceneComponent> parent);
    void AddChild(std::shared_ptr<SceneComponent> child);

    const std::vector<std::shared_ptr<SceneComponent>>& GetChildren() const;

protected:
    Vector2 Position;
    float Rotation;
    Vector2 Scale;

    std::weak_ptr<SceneComponent> Parent;
    std::vector<std::shared_ptr<SceneComponent>> Children;

};

