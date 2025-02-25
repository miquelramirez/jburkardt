FEM1D\_BVP\_LINEAR\
Finite Element Method, 1D, Boundary Value Problem, Piecewise Linear Elements {#fem1d_bvp_linear-finite-element-method-1d-boundary-value-problem-piecewise-linear-elements align="center"}
============================================================================

------------------------------------------------------------------------

**FEM1D\_BVP\_LINEAR** is a C++ program which applies the finite element
method, with piecewise linear elements, to a two point boundary value
problem in one spatial dimension, and compares the computed and exact
solutions with the L2 and seminorm errors.

The boundary value problem (BVP) that is to be solved has the form:

            - d/dx ( a(x) * du/dx ) + c(x) * u(x) = f(x)
          

in the interval 0 &lt; x &lt; 1. The functions a(x), c(x), and f(x) are
given.

Boundary conditions are applied at the endpoints, and in this case,
these are assumed to have the form:

            u(0.0) = 0.0;
            u(1.0) = 0.0.
          

To compute a finite element approximation, a set of n equally spaced
nodes is defined from 0.0 to 1.0, a set of piecewise linear basis
functions is set up, with one basis function associated with each node,
and then an integral form of the BVP is used, in which the differential
equation is multiplied by each basis function, and integration by parts
is used to simplify the integrand.

A simple two point Gauss quadrature formula is used to estimate the
resulting integrals over each interval.

### Usage: {#usage align="center"}

> **fem1d\_bvp\_linear** ( *n*, *a*, *c*, *f*, *x*, *u* )

where

-   *n* is the number of equally spaced nodes.
-   *a* is the function which evaluates a(x);
-   *c* is the function which evaluates c(x);
-   *f* is the function which evaluates f(x).
-   *x* is the input vector of *n* nodes.
-   *u* is the output vector of *n* finite difference values.

### Licensing: {#licensing align="center"}

The computer code and data files described and made available on this
web page are distributed under [the GNU LGPL
license.](../../txt/gnu_lgpl.txt)

### Languages: {#languages align="center"}

**FEM1D\_BVP\_LINEAR** is available in [a C
version](../../c_src/fem1d_bvp_linear/fem1d_bvp_linear.md) and [a C++
version](../../master/fem1d_bvp_linear/fem1d_bvp_linear.md) and [a
FORTRAN77 version](../../f77_src/fem1d_bvp_linear/fem1d_bvp_linear.md)
and [a FORTRAN90
version](../../f_src/fem1d_bvp_linear/fem1d_bvp_linear.md) and [a
MATLAB version](../../m_src/fem1d_bvp_linear/fem1d_bvp_linear.md) and
[a Python version](../../py_src/fem1d_bvp_linear/fem1d_bvp_linear.md).

### Related Data and Programs: {#related-data-and-programs align="center"}

[FD1D\_BVP](../../master/fd1d_bvp/fd1d_bvp.md), a C++ program which
applies the finite difference method to a two point boundary value
problem in one spatial dimension.

[FEM1D](../../master/fem1d/fem1d.md), a C++ program which applies the
finite element method to a linear two point boundary value problem in a
1D region.

[FEM1D\_ADAPTIVE](../../master/fem1d_adaptive/fem1d_adaptive.md), a
C++ program which applies the finite element method to a linear two
point boundary value problem in a 1D region, using adaptive refinement
to improve the solution.

[FEM1D\_BVP\_QUADRATIC](../../master/fem1d_bvp_quadratic/fem1d_bvp_quadratic.md),
a C+= program which applies the finite element method (FEM), with
piecewise quadratic elements, to a two point boundary value problem
(BVP) in one spatial dimension, and compares the computed and exact
solutions with the L2 and seminorm errors.

[FEM1D\_HEAT\_STEADY](../../master/fem1d_heat_steady/fem1d_heat_steady.md),
a C++ program which uses the finite element method to solve the steady
(time independent) heat equation in 1D.

[FEM1D\_NONLINEAR](../../master/fem1d_nonlinear/fem1d_nonlinear.md),
a C++ program which applies the finite element method to a nonlinear two
point boundary value problem in a 1D region.

[FEM1D\_PMETHOD](../../master/fem1d_pmethod/fem1d_pmethod.md), a C++
program which applies the p-method version of the finite element method
to a linear two point boundary value problem in a 1D region.

[FEM2D\_BVP\_LINEAR](../../master/fem2d_bvp_linear/fem2d_bvp_linear.md),
a C++ program which applies the finite element method (FEM), with
piecewise linear elements, to a 2D boundary value problem (BVP) in a
rectangle, and compares the computed and exact solutions with the L2 and
seminorm errors.

### Reference: {#reference align="center"}

1.  Dianne O'Leary,\
    Finite Differences and Finite Elements: Getting to Know You,\
    Computing in Science and Engineering,\
    Volume 7, Number 3, May/June 2005.
2.  Dianne O'Leary,\
    Scientific Computing with Case Studies,\
    SIAM, 2008,\
    ISBN13: 978-0-898716-66-5,\
    LC: QA401.O44.
3.  Hans Rudolf Schwarz,\
    Finite Element Methods,\
    Academic Press, 1988,\
    ISBN: 0126330107,\
    LC: TA347.F5.S3313..
4.  Gilbert Strang, George Fix,\
    An Analysis of the Finite Element Method,\
    Cambridge, 1973,\
    ISBN: 096140888X,\
    LC: TA335.S77.
5.  Olgierd Zienkiewicz,\
    The Finite Element Method,\
    Sixth Edition,\
    Butterworth-Heinemann, 2005,\
    ISBN: 0750663200,\
    LC: TA640.2.Z54

### Source Code: {#source-code align="center"}

-   [fem1d\_bvp\_linear.cpp](fem1d_bvp_linear.cpp), the source code.
-   [fem1d\_bvp\_linear.hpp](fem1d_bvp_linear.hpp), the include file.

### Examples and Tests: {#examples-and-tests align="center"}

-   [fem1d\_bvp\_linear\_prb.cpp](fem1d_bvp_linear_prb.cpp), a sample
    calling program.
-   [fem1d\_bvp\_linear\_prb\_output.txt](fem1d_bvp_linear_prb_output.txt),
    the output file.

One of the tests makes convergence plots in the H1, L2 and Max norms.

-   [h1.png](h1.png)
-   [l2.png](l2.png)
-   [mx.png](mx.png)

### List of Routines: {#list-of-routines align="center"}

-   **COMPUTE\_L2\_ERROR** estimates the L2 error norm of a finite
    element solution.
-   **COMPUTE\_SEMINORM\_ERROR** estimates the seminorm error of a
    finite element solution.
-   **FEM1D\_BVP\_LINEAR** solves a two point boundary value problem.
-   **R8MAT\_SOLVE2** computes the solution of an N by N linear system.
-   **R8VEC\_EVEN** returns an R8VEC of evenly spaced values.
-   **TIMESTAMP** prints the current YMDHMS date as a time stamp.

You can go up one level to [the C++ source codes](../cpp_src.md).

------------------------------------------------------------------------

*Last revised on 20 August 2010.*
