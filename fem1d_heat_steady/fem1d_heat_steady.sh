#!/bin/bash
#
cp fem1d_heat_steady.hpp /$HOME/include
#
g++ -c -I /$HOME/include fem1d_heat_steady.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling fem1d_heat_steady.cpp"
  exit
fi
#
mv fem1d_heat_steady.o ~/libcpp/$ARCH/fem1d_heat_steady.o
#
echo "Library installed as ~/libcpp/$ARCH/fem1d_heat_steady.o"
