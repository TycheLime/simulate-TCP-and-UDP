//
// Created by 15428 on 8/2/2025.
//

#ifndef PARSE_TCP_HPP
#define PARSE_TCP_HPP

#include <iostream>
#include <vector>
#include <string>
#include "transport_protocol.hpp"

// 模拟TCP协议
class Tcp : public TransportProtocol{
private:
    std::vector<Packet> receivedPackets;
public:
    void send(const Packet& packet) override;

    std::string receive() override;
};

#endif //PARSE_TCP_HPP
