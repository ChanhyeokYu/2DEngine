#pragma once

#include <vector>

#include "UObject.h"
#include "ActorComponent.h"
#include "SceneComponent.h"

// 액터가 기본적으로 가져야 할 목록을 베이스 클래스화
// 시작, 틱 프레임, 끝
// 액터에 붙혀질 컴포넌트를 가지로 가질 메인 뿌리(Root)를 protected로 설정

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

