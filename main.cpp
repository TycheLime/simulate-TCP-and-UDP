#include <iostream>
#include <thread>
#include <memory>

#include "auxiliary.hpp"
#include "tcp.hpp"
#include "udp.hpp"

int main() {
    std::thread simThread(deviceSimulation);
    simThread.join();

    Packet pkt = {MAC{0x00, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E}, MAC{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
                  IP{192, 168, 1, 10}, IP{192, 168, 1, 1}, Signal{}};

    auto tcpSim = std::make_unique<Tcp>();
    std::unique_ptr<TransportProtocol> udpSim = std::make_unique<Udp>();

    tcpSim->send(pkt);
    std::cout << tcpSim->receive() << std::endl;

    udpSim->send(pkt);
    std::cout << udpSim->receive() << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
