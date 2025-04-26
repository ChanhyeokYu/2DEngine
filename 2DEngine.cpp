// 2DEngine.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <chrono>
#include <thread>

#include "Engine.h"


using namespace std;

int main()
{
	Engine::Initialize();


	while (Engine::IsRunning())
	{
		Engine::Tick(0.016f);
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}

	Engine::Shutdown();

	return 0;

}

