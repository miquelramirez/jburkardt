#!/bin/bash
#
g++ -c -I/$HOME/include ppma_io_prb.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling ppma_io_prb.cpp"
  exit
fi
#
g++ ppma_io_prb.o /$HOME/libcpp/$ARCH/ppma_io.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ppma_io_prb.o."
  exit
fi
#
rm ppma_io_prb.o
#
mv a.out ppma_io_prb
./ppma_io_prb > ppma_io_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running ppma_io_prb."
  exit
fi
rm ppma_io_prb
#
echo "Program output written to ppma_io_prb_output.txt"
