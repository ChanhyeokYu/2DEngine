#pragma once
#include "UObject.h"

class ActorComponent :public UObject
{
public:
	virtual void Initialize() {}
	virtual void Update(float DeltaTime) {}
};

