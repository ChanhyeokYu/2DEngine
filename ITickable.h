#pragma once

// tick�� ��ü ������ ���� �߻� Ŭ����
class ITickable
{
public:
	virtual ~ITickable() = default;
	virtual void Tick(float DeltaTime) = 0;
};