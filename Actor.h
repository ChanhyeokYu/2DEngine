#pragma once

#include <vector>
#include <memory>

#include "UObject.h"
#include "ActorComponent.h"
#include "SceneComponent.h"

class NetworkComponent;
// ���Ͱ� �⺻������ ������ �� ����� ���̽� Ŭ����ȭ
// ����, ƽ ������, ��
// ���Ϳ� ������ ������Ʈ�� ������ ���� ���� �Ѹ�(Root)�� protected�� ����

class Actor : public UObject
{
public:
	Actor();
	Actor(std::shared_ptr<NetworkComponent> networkComp);
	virtual ~Actor() = default;

public:
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);
	virtual void EndPlay();

	void AddComponent(std::shared_ptr<ActorComponent> component);
	void SendNetworkMessage(const std::string& message);

	std::shared_ptr<SceneComponent> GetRootComponent() const { return rootComponent; }

protected:
	std::vector<std::shared_ptr<ActorComponent>> components;
	std::shared_ptr<SceneComponent> rootComponent;
	std::shared_ptr<NetworkComponent> networkComponent;

};

