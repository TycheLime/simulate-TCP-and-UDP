//
// Created by 15428 on 8/2/2025.
//

#include "parse.hpp"

void Parse::run() {
    // 设置启动状态
    SetBit(signal, 0, true);
    std::cout << "After setting start bit:" << std::endl;
    printSignalStatus(signal);

    // 设置系统错误状态
    SetBit(signal, 1, true);
    std::cout << "After setting system error bit:" << std::endl;
    printSignalStatus(signal);

    // 检查是否设置了特定状态
    if(IsBitSet(signal, 0)) {
        std::cout << "Start bit is set." << std::endl;
    }
    if(IsBitSet(signal, 1)) {
        std::cout << "System error bit is set." << std::endl;
    }
}
