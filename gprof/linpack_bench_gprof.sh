#!/bin/bash
#
g++ -c -pg linpack_bench.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling linpack_bench.cpp"
  exit
fi
#
g++ -pg linpack_bench.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading linpack_bench.o"
  exit
fi
rm linpack_bench.o
#
mv a.out linpack_bench
#
./linpack_bench > linpack_bench_output.txt
#
gprof linpack_bench >> linpack_bench_gprof_output.txt
#
#  Clean up.
#
rm linpack_bench
rm gmon.out
#
echo "Program output written to linpack_bench_output.txt"
echo "GPROF report written to linpack_bench_gprof_output.txt"
