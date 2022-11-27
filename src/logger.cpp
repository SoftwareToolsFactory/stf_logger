//                                    .-""-.
//                                   / _  _ \
//                                   |(_)(_)|
// .------------------------------ooO(_ /\ _)Ooo-----------------------------.
// |                                  |====|                                 |
// |                                  '-..-'                                 |
// | Desc: STF Logger main include file                                      |
// |                                                                         |
// | By: Nuroferatu - https://github.com/Nuroferatu                          |
// |                                                                         |
// | Copyright (C)2022 SoftwareToolsFactory                                  |
// |                   http://softwaretoolsfactory.com                       |
// '-------------------------------------------------------------------------'
#include "logger.h"

#include <iostream>
#pragma region Windows Color Control
#ifdef _WIN32
#include <Windows.h>

static HANDLE stdOutputHandle = INVALID_HANDLE_VALUE;
static WORD   consoleNormalColor = 0;

static void initConsoleColor( void ) {
    if( stdOutputHandle == INVALID_HANDLE_VALUE ) {
        stdOutputHandle = GetStdHandle( STD_OUTPUT_HANDLE );
        if( stdOutputHandle == INVALID_HANDLE_VALUE )
            return;

        CONSOLE_SCREEN_BUFFER_INFO buffInfo;
        GetConsoleScreenBufferInfo( stdOutputHandle, &buffInfo );
        consoleNormalColor = buffInfo.wAttributes;
    }
}

static void setConsoleNormalColor() {
    if( stdOutputHandle == INVALID_HANDLE_VALUE )
        return;
    SetConsoleTextAttribute( stdOutputHandle, consoleNormalColor );
}

static void setConsoleColor( WORD color ) {
    if( stdOutputHandle == INVALID_HANDLE_VALUE )
        return;
    SetConsoleTextAttribute( stdOutputHandle, color );
}
#endif // def _WIN32
#pragma endregion

namespace stf {

// ---------------------------------------------------------------------------
// Logger
// ---------------------------------------------------------------------------
Logger::Logger( const std::string& name ) : _name( name ) {
}

// ---------------------------------------------------------------------------
// Log
// ---------------------------------------------------------------------------
#pragma region cTor/Dtor
Log::Log( const std::string& name ) : d( name ), i( name ), w( name ), e( name ), _name( name ) {
#ifdef _WIN32
    initConsoleColor();
#endif
}

Log::~Log() {
}
#pragma endregion

// Color control
#ifdef _WIN32

Logger& Logger::setColor( const logutils::Color& color ) {
    switch( color ) {
         case logutils::Color::eReset:   setConsoleNormalColor(); break;

         case logutils::Color::eWhite:   setConsoleColor( FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN ); break;
         case logutils::Color::eRed:     setConsoleColor( FOREGROUND_RED ); break;
         case logutils::Color::eGreen:   setConsoleColor( FOREGROUND_GREEN ); break;
         case logutils::Color::eBlue:    setConsoleColor( FOREGROUND_BLUE ); break;
         case logutils::Color::eCyan:    setConsoleColor( FOREGROUND_GREEN | FOREGROUND_BLUE ); break;
         case logutils::Color::eMagneta: setConsoleColor( FOREGROUND_BLUE | FOREGROUND_RED ); break;
         case logutils::Color::eYellow:  setConsoleColor( FOREGROUND_GREEN | FOREGROUND_RED ); break;

         case logutils::Color::eIntenseWhite:   setConsoleColor( FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY ); break;
         case logutils::Color::eIntenseRed:     setConsoleColor( FOREGROUND_RED | FOREGROUND_INTENSITY ); break;
         case logutils::Color::eIntenseGreen:   setConsoleColor( FOREGROUND_GREEN | FOREGROUND_INTENSITY ); break;
         case logutils::Color::eIntenseBlue:    setConsoleColor( FOREGROUND_BLUE | FOREGROUND_INTENSITY ); break;
         case logutils::Color::eIntenseCyan:    setConsoleColor( FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ); break;
         case logutils::Color::eIntenseMagneta: setConsoleColor( FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); break;
         case logutils::Color::eIntenseYellow:  setConsoleColor( FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY ); break;
    }
    return *this;
}

#elif __linux__ || __CYGWIN__

Logger& Logger::setColor( const logutils::Color& color ) {
    switch( color ) {
        case logutils::Color::eReset:   std::cout << "\033[0;0m"; break;

        case logutils::Color::eRed:             std::cout << "\033[0;31m"; break;
        case logutils::Color::eGreen:           std::cout << "\033[0;32m"; break;
        case logutils::Color::eYellow:          std::cout << "\033[0;33m"; break;
        case logutils::Color::eBlue:            std::cout << "\033[0;34m"; break;
        case logutils::Color::eMagneta:         std::cout << "\033[0;35m"; break;
        case logutils::Color::eCyan:            std::cout << "\033[0;36m"; break;
        case logutils::Color::eWhite:           std::cout << "\033[0;37m"; break;

        case logutils::Color::eIntenseRed:      std::cout << "\033[1;31m"; break;
        case logutils::Color::eIntenseGreen:    std::cout << "\033[1;32m"; break;
        case logutils::Color::eIntenseYellow:   std::cout << "\033[1;33m"; break;
        case logutils::Color::eIntenseBlue:     std::cout << "\033[1;34m"; break;
        case logutils::Color::eIntenseMagneta:  std::cout << "\033[1;35m"; break;
        case logutils::Color::eIntenseCyan:     std::cout << "\033[1;36m"; break;
        case logutils::Color::eIntenseWhite:    std::cout << "\033[1;37m"; break;
    }
    return *this;
}

#endif

// Global logger to make usage as simple as cout
Log    theLog( "theLog" );

} //ns:stf

// vim: ts=4:sw=4:et:nowrap
