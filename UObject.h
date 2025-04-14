#pragma once
#include <string>
#include <memory>

// 모든 객체의 시작점

class UObject
{
public:
	UObject() = default;
	virtual ~UObject() = default;

	virtual std::string GetName() const { return Name; }

protected:
	std::string Name;

};

