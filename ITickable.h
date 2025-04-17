#pragma once

// tick의 객체 관리를 위한 추상 클래스
class ITickable
{
public:
	virtual ~ITickable() = default;
	virtual void Tick(float DeltaTime) = 0;
};