//
// Created by 15428 on 8/2/2025.
//
#include "udp.hpp"

void Udp::send(const Packet &packet) {
    // UDP发送逻辑：直接发送数据包，不保证顺序或送达
    std::cout << "Sending via UDP: " << packet << std::endl;
    receivedPackets.push_back(packet);
}

std::string Udp::receive() {
    if(!receivedPackets.empty()) {
        auto pkt = receivedPackets.back();
        receivedPackets.pop_back();
        return "[UDP Received] SRC IP: " + std::to_string(pkt.srcIP.byte4) +
               ", DEST MAC: " + std::to_string(pkt.destMac.bytes[5]); // 简化输出
    }
    return "No packets to receive.";
}