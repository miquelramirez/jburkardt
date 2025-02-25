FEYNMAN\_KAC\_2D\
PDE Solution by Feynman-Kac Algorithm {#feynman_kac_2d-pde-solution-by-feynman-kac-algorithm align="center"}
=====================================

------------------------------------------------------------------------

**FEYNMAN\_KAC\_2D** is a C++ program which demonstrates the use of the
Feynman-Kac algorithm to solve Poisson's equation in a 2D ellipse by
averaging stochastic paths to the boundary.

The program is intended as a simple demonstration of the method. The
main purpose is to have a version that runs sequentially, so that it can
be compared to versions which have been enhanced using parallel
programming techniques.

### Licensing: {#licensing align="center"}

The computer code and data files described and made available on this
web page are distributed under [the GNU LGPL
license.](../../txt/gnu_lgpl.txt)

### Languages: {#languages align="center"}

**FEYNMAN\_KAC\_2D** is available in [a C
version](../../c_src/feynman_kac_2d/feynman_kac_2d.md) and [a C++
version](../../master/feynman_kac_2d/feynman_kac_2d.md) and [a
FORTRAN77 version](../../f77_src/feynman_kac_2d/feynman_kac_2d.md) and
[a FORTRAN90 version](../../f_src/feynman_kac_2d/feynman_kac_2d.md)
and [a MATLAB version.](../../m_src/feynman_kac_2d/feynman_kac_2d.md)

### Related Data and Programs: {#related-data-and-programs align="center"}

[FEYNMAN\_KAC\_1D](../../master/feynman_kac_1d/feynman_kac_1d.md), a
C++ program which demonstrates the use of the Feynman-Kac algorithm to
solve Poisson's equation in a 1D interval by averaging stochastic paths
to the boundary.

[FEYNMAN\_KAC\_3D](../../master/feynman_kac_3d/feynman_kac_3d.md), a
C++ program which demonstrates the use of the Feynman-Kac algorithm to
solve Poisson's equation in a 3D ellipsoid by averaging stochastic paths
to the boundary.

[SDE](../../m_src/sde/sde.md), a MATLAB library which solves certain
stochastic differential equations.

[STOCHASTIC\_RK](../../master/stochastic_rk/stochastic_rk.md), a C++
library which applies a Runge-Kutta scheme to a stochastic differential
equation.

### Reference: {#reference align="center"}

1.  Peter Arbenz, Wesley Petersen,\
    Introduction to Parallel Computing - A practical guide with examples
    in C,\
    Oxford University Press,\
    ISBN: 0-19-851576-6,\
    LC: QA76.58.P47.

### Source Code: {#source-code align="center"}

-   [feynman\_kac\_2d.cpp](feynman_kac_2d.cpp), the source code.

### Examples and Tests: {#examples-and-tests align="center"}

-   [feynman\_kac\_2d\_output.txt](feynman_kac_2d_output.txt), the
    output file.

### List of Routines: {#list-of-routines align="center"}

-   **MAIN** is the main program for FEYNMAN\_KAC\_2D.
-   **POTENTIAL** evaluates the potential function V(X,Y).
-   **R8\_ABS** returns the absolute value of an R8.
-   **R8\_UNIFORM\_01** returns a unit pseudorandom R8.
-   **TIMESTAMP** prints the current YMDHMS date as a time stamp.

You can go up one level to [the C++ source codes](../cpp_src.md).

------------------------------------------------------------------------

*Last revised on 16 November 2011.*
