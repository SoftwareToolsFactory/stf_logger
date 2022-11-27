#!/bin/bash
OS_NAME=$(uname -s | tr A-Z a-z)
BIN=bin/$OS_NAME

case "$OS_NAME" in
    linux*)
        EXE=$BIN/logger_test
        ;;

    cygwin*)
        EXE=$BIN/logger_test.exe
        ;;
    *)
        echo "Unknown system : uname = "$OS_NAME
esac
./$EXE