#!/usr/bin/env bash
# git submodule update --init --recursive || exit 1
# export PATH="$PATH:$(pwd)/xtensa-esp32-elf/bin"
cd firmware
bash mpy_cross.sh || exit 1
rm  -rf build
make clean
make -j8
