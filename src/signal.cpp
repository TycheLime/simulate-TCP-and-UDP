//
// Created by 15428 on 8/2/2025.
//
#include "singal.hpp"

void printSignalStatus(const Signal& status) {
    std::cout << "Signal Status (Binary): " << status.toBinary() << std::endl;
}

void SetBit(Signal& signal, int bitPosition, bool value){
    if(bitPosition < 0 || bitPosition >= 16){
        return;
    }

    unsigned short* signalShort = reinterpret_cast<unsigned short*>(&signal);
    if(value){
        *signalShort |= (0x1 << bitPosition);
    } else{
        *signalShort &= ~(0x1 << bitPosition);
    }
}

bool IsBitSet(const Signal& signal, int bitPosition){
    if(bitPosition < 0 || bitPosition >= 16){
        return false;
    }

    const unsigned short* signalAsShort = reinterpret_cast<const unsigned short*>(&signal);
    return (*signalAsShort & (1 << bitPosition)) != 0;
}