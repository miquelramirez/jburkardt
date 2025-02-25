GEGENBAUER\_EXACTNESS\
Exactness of Gauss-Gegenbauer Quadrature Rules {#gegenbauer_exactness-exactness-of-gauss-gegenbauer-quadrature-rules align="center"}
==============================================

------------------------------------------------------------------------

**GEGENBAUER\_EXACTNESS** is a C++ program which investigates the
polynomial exactness of a Gauss-Gegenbauer quadrature rule for the
interval \[-1,1\] with a weight function.

The Gauss-Gegenbauer quadrature rule is designed to approximate
integrals on the interval \[-1,1\], with a weight function of the form
**(1-x\^2)^ALPHA^**. ALPHA is a real parameter that must be greater than
-1.

Gauss-Gegenbauer quadrature assumes that the integrand we are
considering has a form like:

            Integral ( -1 <= x <= +1 ) (1-x^2)^alpha f(x) dx
          

For a Gauss-Gegenbauer rule, polynomial exactness is defined in terms of
the function **f(x)**. That is, we say the rule is exact for polynomials
up to degree DEGREE\_MAX if, for any polynomial **f(x)** of that degree
or less, the quadrature rule will produce the exact value of

            Integral ( -1 <= x <= +1 ) (1-x^2)^alpha f(x) dx
          

The program starts at **DEGREE** = 0, and then proceeds to **DEGREE** =
1, 2, and so on up to a maximum degree **DEGREE\_MAX** specified by the
user. At each value of **DEGREE**, the program generates the
corresponding monomial term, applies the quadrature rule to it, and
determines the quadrature error.

The program is very flexible and interactive. The quadrature rule is
defined by three files, to be read at input, and the maximum degree top
be checked is specified by the user as well.

Note that the three files that define the quadrature rule are assumed to
have related names, of the form

-   *prefix*\_**x.txt**
-   *prefix*\_**w.txt**
-   *prefix*\_**r.txt**

When running the program, the user only enters the common *prefix* part
of the file names, which is enough information for the program to find
all three files.

For information on the form of these files, see the
**QUADRATURE\_RULES** directory listed below.

The exactness results are written to an output file with the
corresponding name:

-   *prefix*\_**exact.txt**

### Usage: {#usage align="center"}

> **gegenbauer\_exactness** *prefix* *degree\_max* *alpha*

where

-   *prefix* is the common prefix for the files containing the abscissa,
    weight and region information of the quadrature rule;
-   *degree\_max* is the maximum monomial degree to check. This would
    normally be a relatively small nonnegative number, such as 5, 10
    or 15.
-   *alpha* is the value of the exponent of (1-x\^2) in the weight
    function; **alpha** should be a real number greater than -1.0.

If the arguments are not supplied on the command line, the program will
prompt for them.

### Licensing: {#licensing align="center"}

The computer code and data files described and made available on this
web page are distributed under [the GNU LGPL
license.](../../txt/gnu_lgpl.txt)

### Languages {#languages align="center"}

**GEGENBAUER\_EXACTNESS** is available in [a C++
version](../../master/gegenbauer_exactness/gegenbauer_exactness.md)
and [a FORTRAN90
version](../../f_src/gegenbauer_exactness/gegenbauer_exactness.md) and
[a MATLAB
version](../../m_src/gegenbauer_exactness/gegenbauer_exactness.md)

### Related Data and Programs: {#related-data-and-programs align="center"}

[GEGENBAUER\_CC](../../master/gegenbauer_cc/gegenbauer_cc.md), a C++
library which estimates the Gegenbauer weighted integral of a function
f(x) using a Clenshaw-Curtis approach.

[GEGENBAUER\_RULE](../../master/gegenbauer_rule/gegenbauer_rule.md),
a C++ program which can generate a Gauss-Gegenbauer quadrature rule on
request.

[HERMITE\_EXACTNESS](../../master/hermite_exactness/hermite_exactness.md),
a C++ program which tests the polynomial exactness of Gauss-Hermite
quadrature rules.

[INT\_EXACTNESS](../../master/int_exactness/int_exactness.md), a C++
program which tests the polynomial exactness of a quadrature rule for a
finite interval.

[INT\_EXACTNESS\_CHEBYSHEV1](../../master/int_exactness_chebyshev1/int_exactness_chebyshev1.md),
a C++ program which tests the polynomial exactness of Gauss-Chebyshev
type 1 quadrature rules.

[INT\_EXACTNESS\_CHEBYSHEV2](../../master/int_exactness_chebyshev2/int_exactness_chebyshev2.md),
a C++ program which tests the polynomial exactness of Gauss-Chebyshev
type 2 quadrature rules.

[INT\_EXACTNESS\_GEN\_HERMITE](../../master/int_exactness_gen_hermite/int_exactness_gen_hermite.md),
a C++ program which tests the polynomial exactness of generalized
Gauss-Hermite quadrature rules.

[INT\_EXACTNESS\_GEN\_LAGUERRE](../../master/int_exactness_gen_laguerre/int_exactness_gen_laguerre.md),
a C++ program which tests the polynomial exactness of generalized
Gauss-Laguerre quadrature rules.

[INT\_EXACTNESS\_JACOBI](../../master/int_exactness_jacobi/int_exactness_jacobi.md),
a C++ program which tests the polynomial exactness of Gauss-Jacobi
quadrature rules.

[LAGUERRE\_EXACTNESS](../../master/laguerre_exactness/laguerre_exactness.md),
a C++ program which tests the polynomial exactness of Gauss-Laguerre
quadrature rules for integration over \[0,+oo) with density function
exp(-x).

[LEGENDRE\_EXACTNESS](../../master/legendre_exactness/legendre_exactness.md),
a C++ program which tests the monomial exactness of quadrature rules for
the Legendre problem of integrating a function with density 1 over the
interval \[-1,+1\].

### Reference: {#reference align="center"}

1.  Philip Davis, Philip Rabinowitz,\
    Methods of Numerical Integration,\
    Second Edition,\
    Dover, 2007,\
    ISBN: 0486453391,\
    LC: QA299.3.D28.
2.  Shanjie Zhang, Jianming Jin,\
    Computation of Special Functions,\
    Wiley, 1996,\
    ISBN: 0-471-11963-6,\
    LC: QA351.C45.

### Source Code: {#source-code align="center"}

-   [gegenbauer\_exactness.cpp](gegenbauer_exactness.cpp), the source
    code.

### Examples and Tests: {#examples-and-tests align="center"}

**GEGEN\_O1\_A0.5** is a Gauss-Gegenbauer order 1 rule with ALPHA = 0.5.

-   [gegen\_o1\_a0.5\_x.txt](../../datasets/quadrature_rules_jacuerre/gegen_o1_a0.5_x.txt),
    the abscissas of the rule.
-   [gegen\_o1\_a0.5\_w.txt](../../datasets/quadrature_rules_jacuerre/gegen_o1_a0.5_w.txt),
    the weights of the rule.
-   [gegen\_o1\_a0.5\_r.txt](../../datasets/quadrature_rules_jacuerre/gegen_o1_a0.5_r.txt),
    defines the region for the rule.
-   [gegen\_o1\_a0.5\_exact.txt](gegen_o1_a0.5_exact.txt), the results
    of the command

    > **gegenbauer\_exactness gegen\_o1\_a0.5 5 0.5**

**GEGEN\_O2\_A0.5** is a Gauss-Gegenbauer order 2 rule with ALPHA = 0.5.

-   [gegen\_o2\_a0.5\_x.txt](../../datasets/quadrature_rules_jacuerre/gegen_o2_a0.5_x.txt),
    the abscissas of the rule.
-   [gegen\_o2\_a0.5\_w.txt](../../datasets/quadrature_rules_jacuerre/gegen_o2_a0.5_w.txt),
    the weights of the rule.
-   [gegen\_o2\_a0.5\_r.txt](../../datasets/quadrature_rules_jacuerre/gegen_o2_a0.5_r.txt),
    defines the region for the rule.
-   [gegen\_o2\_a0.5\_exact.txt](gegen_o2_a0.5_exact.txt), the results
    of the command

    > **gegenbauer\_exactness gegen\_o2\_a0.5 5 0.5**

**GEGEN\_O4\_A0.5** is a Gauss-Gegenbauer order 4 rule with ALPHA = 0.5.

-   [gegen\_o4\_a0.5\_x.txt](../../datasets/quadrature_rules_jacuerre/gegen_o4_a0.5_x.txt),
    the abscissas of the rule.
-   [gegen\_o4\_a0.5\_w.txt](../../datasets/quadrature_rules_jacuerre/gegen_o4_a0.5_w.txt),
    the weights of the rule.
-   [gegen\_o4\_a0.5\_r.txt](../../datasets/quadrature_rules_jacuerre/gegen_o4_a0.5_r.txt),
    defines the region for the rule.
-   [gegen\_o4\_a0.5\_exact.txt](gegen_o4_a0.5_exact.txt), the results
    of the command

    > **gegenbauer\_exactness gegen\_o4\_a0.5 10 0.5**

**GEGEN\_O8\_A0.5** is a Gauss-Gegenbauer order 8 rule with ALPHA = 0.5.

-   [gegen\_o8\_a0.5\_x.txt](../../datasets/quadrature_rules_jacuerre/gegen_o8_a0.5_x.txt),
    the abscissas of the rule.
-   [gegen\_o8\_a0.5\_w.txt](../../datasets/quadrature_rules_jacuerre/gegen_o8_a0.5_w.txt),
    the weights of the rule.
-   [gegen\_o8\_a0.5\_r.txt](../../datasets/quadrature_rules_jacuerre/gegen_o8_a0.5_r.txt),
    defines the region for the rule.
-   [gegen\_o8\_a0.5\_exact.txt](gegen_o8_a0.5_exact.txt), the results
    of the command

    > **gegenbauer\_exactness gegen\_o8\_a0.5 18 0.5**

**GEGEN\_O16\_A0.5** is a Gauss-Gegenbauer order 16 rule with ALPHA =
0.5.

-   [gegen\_o16\_a0.5\_x.txt](../../datasets/quadrature_rules_jacuerre/gegen_o16_a0.5_x.txt),
    the abscissas of the rule.
-   [gegen\_o16\_a0.5\_w.txt](../../datasets/quadrature_rules_jacuerre/gegen_o16_a0.5_w.txt),
    the weights of the rule.
-   [gegen\_o16\_a0.5\_r.txt](../../datasets/quadrature_rules_jacuerre/gegen_o16_a0.5_r.txt),
    defines the region for the rule.
-   [gegen\_o16\_a0.5\_exact.txt](gegen_o16_a0.5_exact.txt), the results
    of the command

    > **gegenbauer\_exactness gegen\_o16\_a0.5 35 0.5**

### List of Routines: {#list-of-routines align="center"}

-   **MAIN** is the main program for GEGENBAUER\_EXACTNESS.
-   **CH\_CAP** capitalizes a single character.
-   **CH\_EQI** is true if two characters are equal, disregarding case.
-   **CH\_TO\_DIGIT** returns the integer value of a base 10 digit.
-   **DTABLE\_DATA\_READ** reads the data from a DTABLE file.
-   **DTABLE\_HEADER\_READ** reads the header from a DTABLE file.
-   **FILE\_COLUMN\_COUNT** counts the number of columns in the first
    line of a file.
-   **FILE\_ROW\_COUNT** counts the number of row records in a file.
-   **GEGENBAUER\_INTEGRAL** evaluates the integral of a monomial with
    Gegenbauer weight.
-   **MONOMIAL\_QUADRATURE\_GEGENBAUER** applies a quadrature rule to a
    monomial.
-   **R8\_ABS** returns the absolute value of an R8.
-   **R8\_GAMMA** evaluates Gamma(X) for a real argument.
-   **R8\_HUGE** returns a "huge" R8.
-   **R8\_HYPER\_2F1** evaluates the hypergeometric function
    2F1(A,B,C,X).
-   **R8\_PSI** evaluates the function Psi(X).
-   **S\_LEN\_TRIM** returns the length of a string to the last
    nonblank.
-   **S\_TO\_I4** reads an I4 from a string.
-   **S\_TO\_R8** reads an R8 from a string.
-   **S\_TO\_R8VEC** reads an R8VEC from a string.
-   **S\_WORD\_COUNT** counts the number of "words" in a string.
-   **TIMESTAMP** prints the current YMDHMS date as a time stamp.
-   **TIMESTRING** returns the current YMDHMS date as a string.

You can go up one level to [the C++ source codes](../cpp_src.md).

------------------------------------------------------------------------

*Last revised on 03 March 2008.*
