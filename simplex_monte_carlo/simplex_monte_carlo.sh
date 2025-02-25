#!/bin/bash
#
cp simplex_monte_carlo.hpp /$HOME/include
#
g++ -c -I /$HOME/include simplex_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling simplex_monte_carlo.cpp"
  exit
fi
#
mv simplex_monte_carlo.o ~/libcpp/$ARCH/simplex_monte_carlo.o
#
echo "Library installed as ~/libcpp/$ARCH/simplex_monte_carlo.o"
