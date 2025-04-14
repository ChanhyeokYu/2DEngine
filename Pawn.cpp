#include "Pawn.h"

void Pawn::Move(float x, float y)
{
	auto pos = GetRootComponent()->GetPosition();
	GetRootComponent()->SetPosition(pos.X + x, pos.Y + y);
}
