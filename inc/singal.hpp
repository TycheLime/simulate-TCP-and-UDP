//
// Created by 15428 on 8/2/2025.
//

#ifndef PARSE_SINGAL_HPP
#define PARSE_SINGAL_HPP
#include <iostream>
#include <bitset>
#include <string>

struct Signal{
    unsigned int power : 1;  // 设备是否开机（0: 关, 1: 开）
    unsigned int alarm : 1;     // 是否有警报
    unsigned int error : 1;     // 是否有故障
    unsigned int overheat : 1;  // 是否过热
    unsigned int reserved : 12; // 预留位

    // 获取整个信号的二进制表示
    std::string toBinary() const {
        return std::bitset<16>(*(reinterpret_cast<const unsigned short*>(this))).to_string();
    }
};

// 用于打印信号状态的函数
void printSignalStatus(const Signal& status);

// 设置 Signal 的某个位
void SetBit(Signal& signal, int bitPosition, bool value);

// 函数用于检查Signal结构体中指定位是否被设置
bool IsBitSet(const Signal& signal, int bitPosition);

#endif //PARSE_SINGAL_HPP
