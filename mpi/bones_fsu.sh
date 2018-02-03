#!/bin/bash
#
#  Name this job.
#
#MOAB -N bones
#
#  Run this job in the "backfill" queue.
#
#MOAB -q backfill
#
#  Request 8 processors.
#
#MOAB -l nodes=1:ppn=8
#
#  Maximum wallclock time :( Hours : Minutes : Seconds )
#
#MOAB -l walltime=00:02:00
#
#  Join the two output files (standard output and standard error) into one.
#  Based on the job name, this means the single output file will be called
#  "bones.oJOBID" where JOBID is a job id number assigned when the job is
#  submitted.
#
#MOAB -j oe
#
#  This command is required to set up the Gnu version of OpenMPI.
#
module load gnu-openmpi
#
#  This command moves from your home directory to the directory
#  from which this script was submitted.
#
cd $PBS_O_WORKDIR 
#
#  Compile and load.
#  Wise people do this BEFORE the run!
#
mpiCC bones_mpi.cpp -lm
#
if [ $? -ne 0 ]; then
  echo "Errors compiling bones_mpi.cpp"
  exit
fi
#
#  Rename the executable.
#
mv a.out bones
#
#  Ask MPI to use 8 processes to run your program.
#
mpirun -np 8 ./bones > bones_fsu_output.txt
#
#  Clean up.
#
rm bones
#
echo "Program output written to bones_fsu_output.txt"

