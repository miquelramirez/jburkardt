#!/bin/bash
#
g++ -c -I/$HOME/include sgmg_weight_prb.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling sgmg_weight_prb.cpp"
  exit
fi
#
g++ sgmg_weight_prb.o /$HOME/libcpp/$ARCH/sgmg.o /$HOME/libcpp/$ARCH/sandia_rules.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading sgmg_weight_prb.o."
  exit
fi
#
rm sgmg_weight_prb.o
#
mv a.out sgmg_weight_prb
./sgmg_weight_prb > sgmg_weight_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running sgmg_weight_prb."
  exit
fi
rm sgmg_weight_prb
#
echo "Program output written to sgmg_weight_prb_output.txt"
