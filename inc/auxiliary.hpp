//
// Created by 15428 on 8/2/2025.
//

#ifndef PARSE_AUXILIARY_HPP
#define PARSE_AUXILIARY_HPP

#include <iostream>
#include <thread>
#include <chrono>

#include "singal.hpp"
#include "mac.hpp"
#include "ip.hpp"
#include "packet.hpp"

inline void deviceSimulation(){
    Signal deviceSignal = {0, 0, 0, 0};  // 设备最初关闭
    MAC deviceMac = {0x00, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E};
    IP deviceIP = {192, 168, 1, 10};
    MAC serverMac = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    IP serverIP = {192, 168, 1, 1};

    for(int i = 0; i < 5; i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // 模拟设备状态变化
        if (i == 1) {
            SetBit(deviceSignal, 0, true); // 开机
        }
        if (i == 2) {
            SetBit(deviceSignal, 3, true);// 过热
        }
        if (i == 3) {
            SetBit(deviceSignal, 1, true); // 警报
        }
        if (i == 4) {
            SetBit(deviceSignal, 2, true); // 故障
        }

        printSignalStatus(deviceSignal);

        // 设备每次变化后发送数据包
        Packet pkt = {deviceMac, serverMac, deviceIP, serverIP, deviceSignal};
        sendPacket(pkt);
    }
}

#endif //PARSE_AUXILIARY_HPP
