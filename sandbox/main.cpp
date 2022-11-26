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
#include "logger.h"
#include <iostream>

int main( void ) {
    stf::theLog.i << "Test operator << ( const char* msg )[Expected: Test :)]: " << " Test :)" << std::endl;
    stf::theLog.i << "Test operator << ( bool val )[Expected: 1 0]: " << true << " " << false << std::endl;
    stf::theLog.i << "Test operator << ( bool val )<bool alpha>: [Expected: true false]" << std::boolalpha << true << " : " << false << std::noboolalpha << std::endl;
    stf::theLog.i << "Test operator << ( short val )[Expected: -1234]: " << (short) -1234 << std::endl;
    stf::theLog.i << "Test operator << ( unsigned short val )[Expected: 12345]: " <<  (unsigned short) 12345 << std::endl;
    stf::theLog.i << "Test operator << ( int val )[Expected: -123454678]: " << (int)-123454678 << std::endl;
    stf::theLog.i << "Test operator << ( unsigned int val )[Expected: 123454678]: " << (unsigned int) 123454678 << std::endl;
    stf::theLog.i << "Test operator << ( long val )[Expected: -1]: " << (long) 0xFFFFFFFF << std::endl;
    stf::theLog.i << "Test operator << ( long val )<hex>[Expected: 0xffffffff]: " << "0x" << std::hex << (long) 0xFFFFFFFF << std::dec << std::endl;
    stf::theLog.i << "Test operator << ( long val )<hex><uppercase>[Expected: 0xFFFFFFFF]: " << "0x" << std::hex << std::uppercase << (long) 0xFFFFFFFF << std::nouppercase << std::dec << std::endl;
    stf::theLog.i << "Test operator << ( unsigned long val )[Expected: 4294967295]: " << (unsigned long) 0xFFFFFFFF << std::endl;
    stf::theLog.i << "Test operator << ( long long val )[Expected: 4294967295]: " << (long long) 0xFFFFFFFF << std::endl;
    stf::theLog.i << "Test operator << ( unsigned long long val )[Expected: 4294967295]: " << (unsigned long long) 0xFFFFFFFF << std::endl;
    stf::theLog.i << "Test operator << ( long long val )[Expected: -1]: " << (long long) 0xFFFFFFFFFFFFFFFF << std::endl;
    stf::theLog.i << "Test operator << ( unsigned long long val )[Expected: 18446744073709551615]: " << (unsigned long long) 0xFFFFFFFFFFFFFFFF << std::endl;
    stf::theLog.i << "Test operator << ( float val )[Expected: 1.1234] " << (float)1.1234f << std::endl;
    stf::theLog.i << "Test operator << ( double val )[Expected: 1.1234] " << (double)1.12345f << std::endl;
    stf::theLog.i << "Test operator << ( long double val )[Expected: 1.1234] " << (long double)1.12345f << std::endl;
    stf::theLog.i << "Test operator << ( const void* nullptr )[Expected: 0000000000000000] " << (const void*)nullptr << std::endl;

    stf::theLog.i << stf::cwhite << "stf::logutils::Color::eWhite" << stf::creset << std::endl;
    stf::theLog.i << stf::ciwhite << "stf::logutils::Color::eIntenseWhite" << stf::creset << std::endl;
    stf::theLog.i << stf::cred << "stf::logutils::Color::eRed" << stf::creset << std::endl;
    stf::theLog.i << stf::cired << "stf::logutils::Color::eIntenseRed" << stf::creset << std::endl;
    stf::theLog.i << stf::cgreen << "stf::logutils::Color::eGgreen" << stf::creset << std::endl;
    stf::theLog.i << stf::cigreen << "stf::logutils::Color::eIntenseGreen" << stf::creset << std::endl;
    stf::theLog.i << stf::cblue << "stf::logutils::Color::eBlue" << stf::creset << std::endl;
    stf::theLog.i << stf::ciblue << "stf::logutils::Color::eIntenseBlue" << stf::creset << std::endl;
    stf::theLog.i << stf::ccyan << "stf::logutils::Color::eCyan" << stf::creset << std::endl;
    stf::theLog.i << stf::cicyan << "stf::logutils::Color::eIntenseCyan" << stf::creset << std::endl;
    stf::theLog.i << stf::cmagneta << "stf::logutils::Color::eMagneta" << stf::creset << std::endl;
    stf::theLog.i << stf::cimagneta << "stf::logutils::Color::eIntenseMagneta" << stf::creset << std::endl;
    stf::theLog.i << stf::cyellow << "stf::logutils::Color::eYellow" << stf::creset << std::endl;
    stf::theLog.i << stf::ciyellow << "stf::logutils::Color::eIntenseYellow" << stf::creset << std::endl;

    return 0;
}

// vim: ts=4:sw=4:et:nowrap
