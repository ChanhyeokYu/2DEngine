#pragma once
#include "Actor.h"

// ���� �⺻ ����
// ����� ���길 �߰������� �߰������� ��ӹ��� �⺻ ���۵��� �߰�

class Pawn :
    public Actor
{
public:
    Pawn() = default;
    virtual ~Pawn() = default;

    virtual void Move(float x, float y);

};

