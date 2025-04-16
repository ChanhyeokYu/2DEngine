#pragma once
#include "UObject.h"
#include "ITickable.h"
#include <memory>

// 현재 게임을 진행 중인 월드와 그 월드에서 내가 조종하는 메인 컨트롤러를 둠

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

