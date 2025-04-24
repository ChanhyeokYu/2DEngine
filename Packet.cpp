#include "Packet.h"

Packet::Packet(const std::string& message)
{
    data_.resize(message.size());
    std::memcpy(data_.data(), message.data(), message.size());
}

std::string Packet::ToString() const
{
    return std::string(data_.data(), data_.size());
}
