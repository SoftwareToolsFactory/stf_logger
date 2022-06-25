//                                    .-""-.
//                                   / _  _ \
//                                   |(_)(_)|
// .------------------------------ooO(_ /\ _)Ooo-----------------------------.
// |                                  |====|                                 |
// |                                  '-..-'                                 |
// | Desc: Sandbox main - to test logger                                     |
// |                                                                         |
// | By: Nuroferatu - https://github.com/Nuroferatu                          |
// |                                                                         |
// | Copyright (C)2022 SoftwareToolsFactory                                  |
// |                   http://softwaretoolsfactory.com                       |
// '-------------------------------------------------------------------------'
#include "stf_logger/stf_logger.h"
#include <iostream>

int main( void ) {
    std::cout << "Test" << std::endl;

    stf::stf_print();
    return 0;
}

// vim: ts=4:sw=4:et:nowrap
