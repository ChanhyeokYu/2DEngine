#pragma once
#include "UObject.h"
#include <memory>

// ���� ������ ���� ���� ����� �� ���忡�� ���� �����ϴ� ���� ��Ʈ�ѷ��� ��

class World;
class PlayerController;

class GameMode :
    public UObject
{
public:
    virtual void InitGame(std::shared_ptr<World> world);
    virtual void Tick(float DeltaTime) {};

protected:
    std::shared_ptr<PlayerController> MainPlayerController;
};

