#pragma once
#include "Actor.h"

// 폰은 기본 구조
// 현재는 무브만 추가했지만 추가적으로 상속받을 기본 동작들을 추가

class Pawn :
    public Actor
{
public:
    Pawn() = default;
    virtual ~Pawn() = default;

    virtual void Move(float x, float y);

};

