#pragma once
#include <vector>
#include <string>
#include <cstring>

class Packet
{
public:
	Packet() = default;
	Packet(const std::string& message);

	const char* Data() const { return data_.data(); }
	int Size() const { return static_cast<int>(data_.size()); }

	std::string ToString() const;

private:
	std::vector<char> data_;
};

