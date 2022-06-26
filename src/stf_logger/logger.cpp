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
#include "stf_logger/logger.h"

#include <iostream>
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

namespace stf {

Log::Log() {
    initConsoleColor();
}

Log::~Log() {
}

    // Color control
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

// Global logger to make usage as simple as cout
Log    theLog;

}

// vim: ts=4:sw=4:et:nowrap
