#pragma once
#include "UObject.h"
#include <memory>

class Pawn;

class PlayerController :
    public UObject
{
public:
    void Possess(std::shared_ptr<Pawn> pawn);
    void Tick(float DeltaTime);

private:
    std::shared_ptr<Pawn> ControlledPawn;


};

