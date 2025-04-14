// 2DEngine.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "World.h"
#include "Actor.h"
#include "GameMode.h"
#include <chrono>
#include <thread>

using namespace std;

class TestActor : public Actor
{
	void BeginPlay() override
	{
		GetRootComponent()->SetPosition(100.0f, 200.0f);
	}

	void Tick(float DeltaTime) override
	{
		auto pos = GetRootComponent()->GetPosition();
		::cout << "TestActor Pos: (" << pos.X << ", " << pos.Y << ")" << endl;
	}
};

int main()
{
	auto world = std::make_shared<World>();
	auto gameMode = std::make_shared<GameMode>();

	gameMode->InitGame(world);

	world->SetGameMode(gameMode);
	world->BeginPlay();

	for (int i = 0; i < 5; i++)
	{
		world->Tick(0.016f);
	}

	world->EndPlay();

	return 0;

}

