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
namespace logutils {
    enum class Color {
        eReset,
        eWhite, eRed, eGreen, eBlue, eCyan, eMagneta, eYellow,
        eIntenseWhite, eIntenseRed, eIntenseGreen, eIntenseBlue, eIntenseCyan, eIntenseMagneta, eIntenseYellow
    };
};  // ns:logutils

class Logger {
public:
#pragma region cTor/Dtor
    Logger( const std::string& name );
    ~Logger() = default;
#pragma endregion

#pragma region operator <<
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

    // Support for std::endl/std::hex etc
    Logger& operator<<( std::ostream&(*fn)(std::ostream&) )   { fn(std::cout); return *this; }
    Logger& operator<<( std::ios_base&(*fn)(std::ios_base&) ) { fn(std::cout); return *this; }

    // Support own manips
    Logger& operator<<( Logger&(*fn)(Logger&) ) { fn(*this); return *this; }
#pragma endregion

    // Color control
    Logger& setColor( const logutils::Color& color );

    const std::string&  getName( void ) const { return _name; }

protected:
    const std::string   _name;
};

#pragma region Manips::Colors
// Manips::Colors
inline Logger& creset( Logger& other ) { return other.setColor( logutils::Color::eReset ); }
inline Logger& cwhite( Logger& other ) { return other.setColor( logutils::Color::eWhite ); }
inline Logger& cred( Logger& other ) { return other.setColor( logutils::Color::eRed ); }
inline Logger& cgreen( Logger& other ) { return other.setColor( logutils::Color::eGreen ); }
inline Logger& cblue( Logger& other ) { return other.setColor( logutils::Color::eBlue ); }
inline Logger& ccyan( Logger& other ) { return other.setColor( logutils::Color::eCyan ); }
inline Logger& cmagneta( Logger& other ) { return other.setColor( logutils::Color::eMagneta ); }
inline Logger& cyellow( Logger& other ) { return other.setColor( logutils::Color::eYellow ); }
inline Logger& ciwhite( Logger& other ) { return other.setColor( logutils::Color::eIntenseWhite ); }
inline Logger& cired( Logger& other ) { return other.setColor( logutils::Color::eIntenseRed ); }
inline Logger& cigreen( Logger& other ) { return other.setColor( logutils::Color::eIntenseGreen ); }
inline Logger& ciblue( Logger& other ) { return other.setColor( logutils::Color::eIntenseBlue ); }
inline Logger& cicyan( Logger& other ) { return other.setColor( logutils::Color::eIntenseCyan ); }
inline Logger& cimagneta( Logger& other ) { return other.setColor( logutils::Color::eIntenseMagneta ); }
inline Logger& ciyellow( Logger& other ) { return other.setColor( logutils::Color::eIntenseYellow ); }
#pragma endregion

class Log {
public:
#pragma region cTor/Dtor
    Log( const std::string& name );
    ~Log();
#pragma endregion

    Logger  d;  // Debug
    Logger  i;  // Info
    Logger  w;  // Warning
    Logger  e;  // Error

    const std::string&  getName( void ) const { return _name; }

protected:
    const std::string   _name;
};

// Global logger to make usage as simple as cout
extern Log    theLog;

}; // ns:stf

#endif /* ndef __STF_LOGGER_H__ */
// vim: ts=4:sw=4:et:nowrap
