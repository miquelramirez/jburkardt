SQUARE\_SYMQ\_RULE\
Symmetric Quadrature Rules for Squares. {#square_symq_rule-symmetric-quadrature-rules-for-squares. align="center"}
=======================================

------------------------------------------------------------------------

**SQUARE\_SYMQ\_RULE** is a C++ library which returns symmetric
quadrature rules, with exactness up to total degree 20, over the
interior of the symmetric square in 2D, by Hong Xiao and Zydrunas
Gimbutas.

The original source code, from which this library was developed, is
available from the Courant Mathematics and Computing Laboratory, at
<http://www.cims.nyu.edu/cmcl/quadratures/quadratures.md>,

### Licensing: {#licensing align="center"}

The computer code and data files made available on this web page are
distributed under [the GNU LGPL license.](../../txt/gnu_lgpl.txt)

### Languages: {#languages align="center"}

**SQUARE\_SYMQ\_RULE** is available in [a C
version](../../c_src/square_symq_rule/square_symq_rule.md) and [a C++
version](../../master/square_symq_rule/square_symq_rule.md) and [a
FORTRAN77 version](../../f77_src/square_symq_rule/square_symq_rule.md)
and [a FORTRAN90
version](../../f_src/square_symq_rule/square_symq_rule.md) and [a
MATLAB version](../../m_src/square_symq_rule/square_symq_rule.md).

### Related Data and Programs: {#related-data-and-programs align="center"}

[CUBE\_FELIPPA\_RULE](../../master/cube_felippa_rule/cube_felippa_rule.md),
a C++ library which returns the points and weights of a Felippa
quadrature rule over the interior of a cube in 3D.

[GNUPLOT](../../master/gnuplot/gnuplot.md), C++ programs which
illustrate how a program can write data and command files so that
gnuplot can create plots of the program results.

[PYRAMID\_FELIPPA\_RULE](../../master/pyramid_felippa_rule/pyramid_felippa_rule.md),
a C++ library which returns Felippa's quadratures rules for
approximating integrals over the interior of a pyramid in 3D.

[SQUARE\_ARBQ\_RULE](../../master/square_arbq_rule/square_arbq_rule.md),
a C++ library which returns quadrature rules, with exactness up to total
degree 20, over the interior of the symmetric square in 2D, by Hong Xiao
and Zydrunas Gimbutas.

[SQUARE\_FELIPPA\_RULE](../../master/square_felippa_rule/square_felippa_rule.md),
a C++ library which returns the points and weights of a Felippa
quadrature rule over the interior of a square in 2D.

[SQUARE\_GRID](../../master/square_grid/square_grid.md), a C++
library which computes a grid of points over the interior of a square in
2D.

[SQUARE\_HEX\_GRID](../../master/square_hex_grid/square_hex_grid.md),
a C++ library which computes a hexagonal grid of points over the
interior of a square in 2D.

[SQUARE\_INTEGRALS](../../master/square_integrals/square_integrals.md),
a C++ library which returns the exact value of the integral of any
monomial over the interior of the unit square in 2D.

[SQUARE\_MONTE\_CARLO](../../master/square_monte_carlo/square_monte_carlo.md),
a C++ library which uses the Monte Carlo method to estimate the integral
of a function over the interior of the unit square in 2D.

[STROUD](../../master/stroud/stroud.md), a C++ library which defines
quadrature rules for a variety of M-dimensional regions, including the
interior of the square, cube and hypercube, the pyramid, cone and
ellipse, the hexagon, the M-dimensional octahedron, the circle, sphere
and hypersphere, the triangle, tetrahedron and simplex, and the surface
of the circle, sphere and hypersphere.

[TOMS886](../../master/toms886/toms886.md), a C++ library which
defines the Padua points for interpolation in a 2D region, including the
rectangle, triangle, and ellipse, by Marco Caliari, Stefano de Marchi,
Marco Vianello. This is a version of ACM TOMS algorithm 886.

[TETRAHEDRON\_FELIPPA\_RULE](../../master/tetrahedron_felippa_rule/tetrahedron_felippa_rule.md),
a C++ library which returns Felippa's quadratures rules for
approximating integrals over the interior of a tetrahedron in 3D.

[TRIANGLE\_FEKETE\_RULE](../../master/triangle_fekete_rule/triangle_fekete_rule.md),
a C++ library which defines Fekete rules for interpolation or quadrature
over the interior of a triangle in 2D.

[TRIANGLE\_FELIPPA\_RULE](../../master/triangle_felippa_rule/triangle_felippa_rule.md),
a C++ library which returns Felippa's quadratures rules for
approximating integrals over the interior of a triangle in 2D.

[TRIANGLE\_SYMQ\_RULE](../../master/triangle_symq_rule/triangle_symq_rule.md),
a C++ library which returns efficient symmetric quadrature rules, with
exactness up to total degree 50, over the interior of an arbitrary
triangle in 2D, by Hong Xiao and Zydrunas Gimbutas.

[WEDGE\_FELIPPA\_RULE](../../master/wedge_felippa_rule/wedge_felippa_rule.md),
a C++ library which returns quadratures rules for approximating
integrals over the interior of the unit wedge in 3D.

### Reference: {#reference align="center"}

1.  Hong Xiao, Zydrunas Gimbutas,\
    A numerical algorithm for the construction of efficient quadrature
    rules in two and higher dimensions,\
    Computers and Mathematics with Applications,\
    Volume 59, 2010, pages 663-676.

### Source Code: {#source-code align="center"}

-   [square\_symq\_rule.cpp](square_symq_rule.cpp), the source code.
-   [square\_symq\_rule.hpp](square_symq_rule.hpp), the include file.

### Examples and Tests: {#examples-and-tests align="center"}

-   [square\_symq\_rule\_prb.cpp](square_symq_rule_prb.cpp), a sample
    calling program.
-   [square\_symq\_rule\_prb\_output.txt](square_symq_rule_prb_output.txt),
    the output file.

SQUARE08 is a degree 8 rule in the symmetric square.

-   [square08.txt](square08.txt), the node coordinates and weights.
-   [square08\_commands.txt](square08_commands.txt), gnuplot commands to
    create a plot.
-   [square08\_nodes.txt](square08_nodes.txt), the node coordinates.
-   [square08\_vertices.txt](square08_vertices.txt), the vertices.
-   [square08.png](square08.png), the PNG image of the point locations.

### List of Routines: {#list-of-routines align="center"}

-   **LEGE2EVA** evaluates orthogonal polynomials on the symmetric
    square.
-   **LLEGEPOLS1** evaluates orthogonal polynomials on the symmetric
    interval.
-   **RULE\_FULL\_SIZE** returns the full size of the requested
    quadrature rule.
-   **RULE01** returns the rule of degree 1.
-   **RULE02** returns the rule of degree 2.
-   **RULE03** returns the rule of degree 3.
-   **RULE04** returns the rule of degree 4.
-   **RULE05** returns the rule of degree 5.
-   **RULE06** returns the rule of degree 6.
-   **RULE07** returns the rule of degree 7.
-   **RULE08** returns the rule of degree 8.
-   **RULE09** returns the rule of degree 9.
-   **RULE10** returns the rule of degree 10.
-   **RULE11** returns the rule of degree 11.
-   **RULE12** returns the rule of degree 12.
-   **RULE13** returns the rule of degree 13.
-   **RULE14** returns the rule of degree 14.
-   **RULE15** returns the rule of degree 15.
-   **RULE16** returns the rule of degree 16.
-   **RULE17** returns the rule of degree 17.
-   **RULE18** returns the rule of degree 18.
-   **RULE19** returns the rule of degree 19.
-   **RULE20** returns the rule of degree 20.
-   **SQUARE\_SYMQ** returns a symmetric quadrature rule for the square.
-   **SQUARE\_SYMQ\_GNUPLOT:** GNUPLOT plot of the symmetric square
    quadrature rule.
-   **TIMESTAMP** prints out the current YMDHMS date as a timestamp.

You can go up one level to [the C++ source codes](../cpp_src.md).

------------------------------------------------------------------------

*Last revised on 02 July 2014.*
