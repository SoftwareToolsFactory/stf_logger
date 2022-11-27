#!/bin/bash -x
CURRENT_DIR=$(basename $PWD)
if [ "$CURRENT_DIR" != "src" ]; then
    pushd src
fi

OS_NAME=$(uname -s | tr A-Z a-z)
BIN_PATH=../bin/$OS_NAME
TMP_PATH=../tmp/$OS_NAME
mkdir -p $BIN_PATH
mkdir -p $TMP_PATH

CXXFLAGS='-Wall -std=c++17 -m64 -Wno-unknown-pragmas -Wno-comment -I../include'

gcc $CXXFLAGS -c logger.cpp -o $TMP_PATH/logger.o
ar rcs $BIN_PATH/libstf_logger.a $TMP_PATH/logger.o

if [ "$CURRENT_DIR" != "src" ]; then
    popd
fi