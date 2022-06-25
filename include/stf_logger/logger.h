//                                    .-""-.
//                                   / _  _ \
//                                   |(_)(_)|
// .------------------------------ooO(_ /\ _)Ooo-----------------------------.
// |                                  |====|                                 |
// |                                  '-..-'                                 |
// | Desc: Logger main include file                                          |
// |                                                                         |
// | By: Nuroferatu - https://github.com/Nuroferatu                          |
// |                                                                         |
// | Copyright (C)2022 SoftwareToolsFactory                                  |
// |                   http://softwaretoolsfactory.com                       |
// '-------------------------------------------------------------------------'
#pragma once
#ifndef __STF_LOGGER_H__
#define __STF_LOGGER_H__

#include <iostream>

namespace stf {

class Logger {
public:
    Logger& operator << ( const char* msg )         { std::cout << msg; return *this; }
    Logger& operator << ( bool val )                { std::cout << val; return *this; }
    Logger& operator << ( short val )               { std::cout << val; return *this; }
    Logger& operator << ( unsigned short val )      { std::cout << val; return *this; }
    Logger& operator << ( int val )                 { std::cout << val; return *this; }
    Logger& operator << ( unsigned int val )        { std::cout << val; return *this; }
    Logger& operator << ( long val )                { std::cout << val; return *this; }
    Logger& operator << ( unsigned long val )       { std::cout << val; return *this; }
    Logger& operator << ( long long val )           { std::cout << val; return *this; }
    Logger& operator << ( unsigned long long val )  { std::cout << val; return *this; }
    Logger& operator << ( float val )               { std::cout << val; return *this; }
    Logger& operator << ( double val )              { std::cout << val; return *this; }
    Logger& operator << ( long double val )         { std::cout << val; return *this; }
    Logger& operator << ( const void* val )         { std::cout << val; return *this; }
};

class Log {
public:
    Logger  d;  // Debug
    Logger  i;  // Info
    Logger  w;  // Warning
    Logger  e;  // Error
};

// Global logger to make usage as simple as cout
extern Log    sysLog;

}; // ns:stf

#endif /* ndef __STF_LOGGER_H__ */
// vim: ts=4:sw=4:et:nowrap
