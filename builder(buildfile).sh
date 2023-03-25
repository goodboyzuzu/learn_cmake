#! /bin/sh
# This script is to create directory called build. if it exists, remove it and create a new one.

if [ -d build ]; then
    rm -rf build
fi
mkdir build