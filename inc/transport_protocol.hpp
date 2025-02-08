//
// Created by 15428 on 8/2/2025.
//

#ifndef PARSE_TRANSPORT_PROTOCOL_HPP
#define PARSE_TRANSPORT_PROTOCOL_HPP

#include <iostream>


#include "packet.hpp"

// 基础传输协议类
class TransportProtocol{
public:
    virtual void send(const Packet& packet) = 0;
    virtual std::string receive() = 0;

};



#endif //PARSE_TRANSPORT_PROTOCOL_HPP
