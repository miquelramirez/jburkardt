#!/bin/bash
#
g++ -c -I/$HOME/include sphere_triangle_quad_prb.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling sphere_triangle_quad_prb.cpp"
  exit
fi
#
g++ sphere_triangle_quad_prb.o /$HOME/libcpp/$ARCH/sphere_triangle_quad.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading sphere_triangle_quad_prb.o."
  exit
fi
#
rm sphere_triangle_quad_prb.o
#
mv a.out sphere_triangle_quad_prb
./sphere_triangle_quad_prb > sphere_triangle_quad_prb_output.txt
if [ $? -ne 0 ]; then
  echo "Errors running sphere_triangle_quad_prb."
  exit
fi
rm sphere_triangle_quad_prb
#
echo "Program output written to sphere_triangle_quad_prb_output.txt"
