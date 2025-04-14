#include "PlayerController.h"
#include "Pawn.h"

void PlayerController::Possess(std::shared_ptr<Pawn> pawn)
{
	ControlledPawn = pawn;
}

void PlayerController::Tick(float DeltaTime)
{
	if (ControlledPawn)
	{
		ControlledPawn->Move(1.0f * DeltaTime, 0.0f);
	}
}
