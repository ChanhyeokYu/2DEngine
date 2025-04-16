#pragma once
#include "UObject.h"
#include "ITickable.h"
#include <memory>

// ���� ������ ���� ���� ����� �� ���忡�� ���� �����ϴ� ���� ��Ʈ�ѷ��� ��

class World;
class PlayerController;

class GameMode :
    public UObject, public ITickable
{
public:
    virtual void InitGame(std::shared_ptr<World> world);
    virtual void Tick(float DeltaTime) override;

protected:
    std::shared_ptr<PlayerController> MainPlayerController;
};

