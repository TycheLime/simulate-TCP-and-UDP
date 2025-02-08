//
// Created by 15428 on 8/2/2025.
//

#ifndef PARSE_MC_HPP
#define PARSE_MC_HPP

#include <iostream>
#include <iomanip> // for std::hex and std::setfill

struct MAC{
    unsigned char bytes[6];

    friend std::ostream& operator<<(std::ostream& os, const MAC& mac) {
        for(int i = 0; i < 6; ++i) {
            os << std::hex << std::setfill('0') << std::setw(2)
               << static_cast<int>(mac.bytes[i]);
            if(i != 5) os << ":";
        }
        return os;
    }
};


#endif //PARSE_MC_HPP
