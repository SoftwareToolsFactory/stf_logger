#!/bin/bash -x
CURRENT_DIR=$(basename $PWD)
if [ "$CURRENT_DIR" != "sandbox" ]; then
    pushd sandbox
fi

OS_NAME=$(uname -s | tr A-Z a-z)
BIN_PATH=../bin/$OS_NAME
TMP_PATH=../tmp/$OS_NAME
mkdir -p $BIN_PATH
mkdir -p $TMP_PATH

CXXFLAGS='-Wall -Wno-comment -std=c++17 -m64 -Wno-unknown-pragmas -I../include'

g++ $CXXFLAGS -c main.cpp -o $TMP_PATH/main.o
g++ $CXXFLAGS -o $BIN_PATH/logger_test $TMP_PATH/main.o -L$BIN_PATH -lstf_logger

if [ "$CURRENT_DIR" != "sandbox" ]; then
    popd
fi