#pragma once
#include <string>
#include <memory>

class UObject
{
public:
	UObject() = default;
	virtual ~UObject() = default;

	virtual std::string GetName() const { return Name; }

protected:
	std::string Name;

};

