//
// Created by 15428 on 8/2/2025.
//

#ifndef PARSE_UDP_HPP
#define PARSE_UDP_HPP
#include <iostream>
#include <vector>
#include <string>
#include "transport_protocol.hpp"

class Udp:public TransportProtocol{
private:
    std::vector<Packet> receivedPackets;
public:
    void send(const Packet& packet) override;

    std::string receive() override;

};

#endif //PARSE_UDP_HPP
