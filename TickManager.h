#pragma once
#include "ITickable.h"
#include <vector>
#include <memory>

// �� Ŭ�������� tick���� ������ ���� �Ŵ��� Ŭ����

class TickManager
{
public:
	void Register(std::shared_ptr<ITickable> tickable);
	void TickAll(float DeltaTime);

private:
	std::vector<std::shared_ptr<ITickable>> Tickables;

};

