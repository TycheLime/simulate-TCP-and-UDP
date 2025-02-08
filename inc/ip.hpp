//
// Created by 15428 on 8/2/2025.
//

#ifndef PARSE_IP_HPP
#define PARSE_IP_HPP

#include <iostream>

// 定义IP结构体
struct IP {
    unsigned char byte1; // IP地址的第一个字节
    unsigned char byte2; // IP地址的第二个字节
    unsigned char byte3; // IP地址的第三个字节
    unsigned char byte4; // IP地址的第四个字节

    IP(): byte1(0), byte2(0), byte3(0), byte4(0){

    }

    // 构造函数
    IP(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
            : byte1(b1), byte2(b2), byte3(b3), byte4(b4) {}

    friend std::ostream& operator<<(std::ostream& os, const IP& ip) {
        os << static_cast<int>(ip.byte1) << "."
           << static_cast<int>(ip.byte2) << "."
           << static_cast<int>(ip.byte3) << "."
           << static_cast<int>(ip.byte4);
        return os;
    }
};

#endif //PARSE_IP_HPP
