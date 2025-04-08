// 2DEngine.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "World.h"
#include "Actor.h"
#include <chrono>
#include <thread>

class TestActor : public Actor
{
	void Tick(float DeltaTime) override
	{
		std::cout << "TestActor is Ticking.... DeltaTime : " << DeltaTime << std:: endl;
	}
};

int main()
{
	auto world = std::make_shared<World>();
	auto player = std::make_shared<TestActor>();
	world->AddActor(player);

	world->BeginPlay();
	for (int i = 0; i < 5; i++)
	{
		world->Tick(0.016f);
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}

	world->EndPlay();

	return 0;

}

