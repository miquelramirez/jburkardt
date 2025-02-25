SEARCH\_MPI\
Parallel Search for Integer so that F(J) = C {#search_mpi-parallel-search-for-integer-so-that-fj-c align="center"}
============================================

------------------------------------------------------------------------

**SEARCH\_MPI** is a C program which searches integers between A and B
for a value J such that F(J) = C, using the MPI parallel programming
environment.

For the particular example considered here, the solution will be
F(1,674,924,981) = 45.

The latest versions of MPI no longer support the special C++ MPI
bindings, so the examples given here have reverted to using the C MPI
bindings.

### Licensing: {#licensing align="center"}

The computer code and data files described and made available on this
web page are distributed under [the GNU LGPL
license.](../../txt/gnu_lgpl.txt)

### Languages: {#languages align="center"}

**SEARCH\_MPI** is available in [a C
version](../../c_src/search_mpi/search_mpi.md) and [a C++
version](../../master/search_mpi/search_mpi.md) and [a FORTRAN77
version](../../f77_src/search_mpi/search_mpi.md) and [a FORTRAN90
version](../../f_src/search_mpi/search_mpi.md) and [a PYTHON
version](../../py_src/search_mpi/search_mpi.md).

### Related Data and Programs: {#related-data-and-programs align="center"}

[COMMUNICATOR\_MPI](../../c_src/communicator_mpi/communicator_mpi.md),
a C program which creates new communicators involving a subset of
initial set of MPI processes in the default communicator
MPI\_COMM\_WORLD.

[HEAT\_MPI](../../c_src/heat_mpi/heat_mpi.md), a C program which
solves the 1D Time Dependent Heat Equation using MPI.

[HELLO\_MPI](../../c_src/hello_mpi/hello_mpi.md), a C program which
prints out "Hello, world!" using the MPI parallel programming
environment.

[MPI](../../c_src/mpi/mpi.md), C programs which illustrate the use of
the MPI application program interface for carrying out parallel
computatioins in a distributed memory environment.

[MULTITASK\_MPI](../../c_src/multitask_mpi/multitask_mpi.md), a C
program which demonstrates how to multitask, that is, to execute several
unrelated and distinct tasks simultaneously, using MPI for parallel
execution.

[PRIME\_MPI](../../c_src/prime_mpi/prime_mpi.md), a C program which
counts the number of primes between 1 and N, using MPI for parallel
execution.

[QUAD\_MPI](../../c_src/quad_mpi/quad_mpi.md), a C program which
approximates an integral using a quadrature rule, and carries out the
computation in parallel using MPI.

[RANDOM\_MPI](../../c_src/random_mpi/random_mpi.md), a C program which
demonstrates one way to generate the same sequence of random numbers for
both sequential execution and parallel execution under MPI.

[RING\_MPI](../../c_src/ring_mpi/ring_mpi.md), a C program which uses
the MPI parallel programming environment, and measures the time
necessary to copy a set of data around a ring of processes.

[SATISFY\_MPI](../../c_src/satisfy_mpi/satisfy_mpi.md), a C program
which demonstrates, for a particular circuit, an exhaustive search for
solutions of the circuit satisfiability problem, using MPI to carry out
the calculation in parallel.

[SEARCH\_SERIAL](../../c_src/search_serial/search_serial.md), a C
program which searches integers between A and B for a value J such that
F(J) = C, intended as a starting point for the creation of a parallel
version.

[WAVE\_MPI](../../master/wave_mpi/wave_mpi.md), a C++ program which
uses finite differences and MPI to estimate a solution to the wave
equation.

### Reference: {#reference align="center"}

1.  William Gropp, Steven Huss-Lederman, Andrew Lumsdaine, Ewing Lusk,
    Bill Nitzberg, William Saphir, Marc Snir,\
    MPI: The Complete Reference,\
    Volume II: The MPI-2 Extensions,\
    Second Edition,\
    MIT Press, 1998.
2.  William Gropp, Ewing Lusk, Anthony Skjellum,\
    Using MPI: Portable Parallel Programming with the Message-Passing
    Interface,\
    Second Edition,\
    MIT Press, 1999,\
    ISBN: 0262571323.
3.  William Gropp, Ewing Lusk, Rajiv Thakur,\
    Using MPI-2: Advanced Features of the Message-Passing Interface,\
    Second Edition,\
    MIT Press, 1999,\
    ISBN: 0262571331.
4.  Stan Openshaw, Ian Turton,\
    High Performance Computing and the Art of Parallel Programming: an
    Introduction for Geographers, Social Scientists, and Engineers,\
    Routledge, 2000,\
    ISBN: 0415156920.
5.  Peter Pacheco,\
    Parallel Programming with MPI,\
    Morgan Kaufman, 1996,\
    ISBN: 1558603395,\
    LC: QA76.642.P3.
6.  Sudarshan Raghunathan,\
    Making a Supercomputer Do What You Want: High Level Tools for
    Parallel Programming,\
    Computing in Science and Engineering,\
    Volume 8, Number 5, September/October 2006, pages 70-80.
7.  Marc Snir, Steve Otto, Steven Huss-Lederman, David Walker, Jack
    Dongarra,\
    MPI: The Complete Reference,\
    Volume I: The MPI Core,\
    Second Edition,\
    MIT Press, 1998,\
    ISBN: 0-262-69216-3,\
    LC: QA76.642.M65.
8.  The MPI web site at Argonne National Lab:
    <http://www-unix.mcs.anl.gov/mpi/>
9.  The Message Passing Interface Forum,\
    **MPI: A Message Passing Interface Standard**,\
    1995,\
    Available online from [the MPI Forum](http://www.mpi-forum.org/).
10. The Message Passing Interface Forum,\
    **MPI-2: Extensions to the Message Passing Interface**,\
    1997,\
    Available online from [the MPI Forum](http://www.mpi-forum.org/).

### Source Code: {#source-code align="center"}

-   [search\_mpi.c](search_mpi.c), the source code.

### Examples and Tests: {#examples-and-tests align="center"}

**SEARCH\_FSU** compiles and runs the program on the FSU HPC cluster.

-   [search\_fsu\_output.txt](search_fsu_output.txt), the output file.

**SEARCH\_LOCAL** compiles and runs the program on the local machine.

-   [search\_local\_output.txt](search_local_output.txt), the output
    file.

You can go up one level to [the C source codes](../c_src.md).

------------------------------------------------------------------------

*Last revised on 01 November 2012.*
