//
// Created by 15428 on 8/2/2025.
//

#ifndef PARSE_PARSE_HPP
#define PARSE_PARSE_HPP
#include "singal.hpp"


class Parse {
public:
    // 定义Parse类的构造函数，并使用成员初始化列表将signal初始化为0
    Parse() : signal{} {
        // 使用空的大括号{}来值初始化signal，这会将所有位域设置为0
    }

    void run();

private:
    Signal signal;

};


#endif //PARSE_PARSE_HPP
