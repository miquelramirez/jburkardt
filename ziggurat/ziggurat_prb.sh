#!/bin/bash
#
g++ -c -I/$HOME/include ziggurat_prb.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling ziggurat_prb.cpp."
  exit
fi
#
g++ ziggurat_prb.o /$HOME/libcpp/$ARCH/ziggurat.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ziggurat_prb.o."
  exit
fi
#
rm ziggurat_prb.o
#
mv a.out ziggurat_prb
./ziggurat_prb > ziggurat_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running ziggurat_prb."
  exit
fi
rm ziggurat_prb
#
echo "Program output written to ziggurat_prb_output.txt"
