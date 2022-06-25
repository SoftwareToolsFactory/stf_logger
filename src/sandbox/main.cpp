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
#include "stf_logger/logger.h"
#include <iostream>

int main( void ) {
    stf::sysLog.i << " Test operator << ( const char* msg ): " << " Test :)" << std::endl;
    stf::sysLog.i << " Test operator << ( bool val ): " << true << " " << false << std::endl;
    stf::sysLog.i << " Test operator << ( bool val )<bool alpha>: " << std::boolalpha << true << " : " << false << std::noboolalpha << std::endl;
    stf::sysLog.i << " Test operator << ( short val ): " << (short) -1234 << std::endl;
    stf::sysLog.i << " Test operator << ( unsigned short val ): " <<  (unsigned short) 12345 << std::endl;
    stf::sysLog.i << " Test operator << ( int val ): " << (int)-123454678 << std::endl;
    stf::sysLog.i << " Test operator << ( unsigned int val ): " << (unsigned int) 123454678 << std::endl;
    stf::sysLog.i << " Test operator << ( long val ): " << (long) 0xFFFFFFFF << std::endl;
    stf::sysLog.i << " Test operator << ( long val )<hex>: " << std::hex << (long) 0xFFFFFFFF << std::dec << std::endl;
    stf::sysLog.i << " Test operator << ( long val )<hex><uppercase>: " << "0x" << std::hex << std::uppercase << (long) 0xFFFFFFFF << std::nouppercase << std::dec << std::endl;
    stf::sysLog.i << " Test operator << ( unsigned long val ): " << (unsigned long) 0xFFFFFFFF << std::endl;
    stf::sysLog.i << " Test operator << ( long long val ): " << (long long) 0xFFFFFFFF << std::endl;
    stf::sysLog.i << " Test operator << ( unsigned long long val ): " << (unsigned long long) 0xFFFFFFFF << std::endl;
    stf::sysLog.i << " Test operator << ( float val ): " << (float)1.1234f << std::endl;
    stf::sysLog.i << " Test operator << ( double val ): " << (double)1.12345f << std::endl;
    stf::sysLog.i << " Test operator << ( long double val ): " << (long double)1.12345f << std::endl;
    stf::sysLog.i << " Test operator << ( const void* val ): " << (const void*)0 << std::endl;

    return 0;
}

// vim: ts=4:sw=4:et:nowrap
