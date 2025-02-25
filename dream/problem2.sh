#!/bin/bash
#
g++ -c -I/$HOME/include problem2.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling problem2.cpp"
  exit
fi
#
g++ /$HOME/libcpp/dream.o \
  problem2.o \
  /$HOME/libcpp/pdflib.o \
  /$HOME/libcpp/rnglib.o -lm
#
if [ $? -ne 0 ]; then
  echo "Errors linking and loading dream.o + problem2.o + pdflib.o + rnglib.o"
  exit
fi
#
rm problem2.o
#
mv a.out problem2
./problem2 > problem2_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running problem2."
  exit
fi
rm problem2
#
echo "Program output written to problem2_output.txt"
