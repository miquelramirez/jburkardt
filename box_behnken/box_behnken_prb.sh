#!/bin/bash
#
g++ -c -I/$HOME/include box_behnken_prb.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling box_behnken_prb.cpp"
  exit
fi
#
g++ box_behnken_prb.o /$HOME/libcpp/$ARCH/box_behnken.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading box_behnken_prb.o."
  exit
fi
#
rm box_behnken_prb.o
#
mv a.out box_behnken_prb
./box_behnken_prb > box_behnken_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running box_behnken_prb."
  exit
fi
rm box_behnken_prb
#
echo "Program output written to box_behnken_prb_output.txt"
