#!/bin/bash
#
g++ -c kronrod_prb.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling kronrod_prb.cpp"
  exit
fi
#
gcc -c kronrod.c
if [ $? -ne 0 ]; then
  echo "Errors compiling kronrod_prb.c"
  exit
fi
#
g++ kronrod_prb.o kronrod.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading kronrod_prb.o + kronrod.o"
  exit
fi
rm kronrod_prb.o
rm kronrod.o
#
mv a.out kronrod_prb
./kronrod_prb > kronrod_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running kronrod"
  exit
fi
rm kronrod_prb
#
echo "Test program output written to kronrod_prb_output.txt."
