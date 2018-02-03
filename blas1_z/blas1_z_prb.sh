#!/bin/bash
#
g++ -c -I$HOME/include blas1_z_prb.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling blas1_z_prb.cpp"
  exit
fi
#
g++ blas1_z_prb.o $HOME/libcpp/$ARCH/blas0.o $HOME/libcpp/$ARCH/blas1_z.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading blas1_z_prb.o."
  exit
fi
#
rm blas1_z_prb.o
#
mv a.out blas1_z_prb
./blas1_z_prb > blas1_z_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running blas1_z_prb."
  exit
fi
rm blas1_z_prb
#
echo "Program output written to blas1_z_prb_output.txt"
