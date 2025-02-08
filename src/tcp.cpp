//
// Created by 15428 on 8/2/2025.
//

#include "tcp.hpp"

void Tcp::send(const Packet& packet){
// TCP发送逻辑：确保数据按序到达，确认收到等
std::cout << "Sending via TCP: " << packet << std::endl;
receivedPackets.push_back(packet);
}

std::string Tcp::receive() {
    if(!receivedPackets.empty()) {
    auto pkt = receivedPackets.back();
    receivedPackets.pop_back();
    return "[TCP Received] SRC MAC: " + std::to_string(pkt.srcMac.bytes[0]) +
    ", DEST IP: " + std::to_string(pkt.destIP.byte4); // 简化输出
    }
    return "No packets to receive.";
}
