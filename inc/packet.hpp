//
// Created by 15428 on 8/2/2025.
//

#ifndef PARSE_PACKET_HPP
#define PARSE_PACKET_HPP

#include <iostream>
#include <vector>

#include "mac.hpp"
#include "ip.hpp"
#include "singal.hpp"

struct Packet {
    MAC srcMac;   // 源 MAC 地址
    MAC destMac;  // 目标 MAC 地址
    IP srcIP;     // 源 IP 地址
    IP destIP;    // 目标 IP 地址
    Signal signalData;  // 信号数据

    friend std::ostream& operator<<(std::ostream& os, const Packet& pkt) {
        os << "[Packet] SRC MAC: " << pkt.srcMac << ", DEST MAC: " << pkt.destMac
           << ", SRC IP: " << pkt.srcIP << ", DEST IP: " << pkt.destIP
           << ", Signal: " << pkt.signalData.toBinary();
        return os;
    }
};

inline void sendPacket(const Packet& pkt) {
    std::cout << "Sending packet: " << pkt << std::endl;
}


#endif //PARSE_PACKET_HPP
