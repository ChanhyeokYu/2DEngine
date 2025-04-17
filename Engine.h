#pragma once
#include "World.h"
#include "GameMode.h"
#include "TickManager.h"
#include <memory>

// 메인 엔진

class Engine
{
public:
	static void Initialize();
	static void Tick(float DeltaTime);
	static void Shutdown();
	static bool IsRunning();

private:
	static inline bool bIsRunning = true;

	static inline std::shared_ptr<World> MainWorld;
	static inline std::shared_ptr<GameMode> MainGameMode;
	static inline TickManager MainTickManager;

};

