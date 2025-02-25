# include <cstdlib>
# include <iostream>
# include <fstream>
# include <iomanip>
# include <cmath>
# include <ctime>
# include <cstring>

using namespace std;

# include "cube_arbq_rule.hpp"

int main ( );
void test01 ( int degree, int n );
void test02 ( int degree, int n, string header );
void test03 ( int degree, int n, string header );
void test04 ( int degree, int n );

//****************************************************************************80

int main ( )

//****************************************************************************80
/*
  Purpose:

    MAIN is the main program for CUBE_ARBQ_RULE_PRB.

  Discussion:

    CUBE_ARBQ_RULE_PRB tests the CUBE_ARBQ_RULE library.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    09 July 2014

  Author:

    Original FORTRAN77 version by Hong Xiao, Zydrunas Gimbutas.
    This C++ version by John Burkardt.

  Reference:

    Hong Xiao, Zydrunas Gimbutas,
    A numerical algorithm for the construction of efficient quadrature
    rules in two and higher dimensions,
    Computers and Mathematics with Applications,
    Volume 59, 2010, pages 663-676.
*/
{
  int degree;
  string header;
  int n;

  timestamp ( );
  cout << "\n";
  cout << "CUBE_ARBQ_RULE_PRB\n";
  cout << "  C version\n";
  cout << "  Test the CUBE_ARBQ_RULE library.\n";

  degree = 8;
  n = cube_arbq_size ( degree );
  strcpy ( header, "cube08" );

  test01 ( degree, n );

  test02 ( degree, n, header );

  test03 ( degree, n, header );

  test04 ( degree, n );
/*
  Terminate.
*/
  cout << "\n";
  cout << "CUBE_ARBQ_RULE_PRB\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test01 ( int degree, int n )

//****************************************************************************80
/*
  Purpose:

    TEST01 calls CUBE_ARBQ for a quadrature rule of given order.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    09 July 2014

  Author:

    Original FORTRAN77 version by Hong Xiao, Zydrunas Gimbutas.
    This C++ version by John Burkardt.

  Reference:

    Hong Xiao, Zydrunas Gimbutas,
    A numerical algorithm for the construction of efficient quadrature
    rules in two and higher dimensions,
    Computers and Mathematics with Applications,
    Volume 59, 2010, pages 663-676.

  Parameters:

    Input, int DEGREE, the desired total polynomial degree exactness
    of the quadrature rule.

    Input, int N, the number of nodes.
*/
{
  double d;
  int j;
  double volume;
  double *w;
  double *x;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  Symmetric quadrature rule for a cube.\n";
  cout << "  Polynomial exactness degree DEGREE = " << degree << "\n";

  volume = 8.0;
/*
  Retrieve and print a symmetric quadrature rule.
*/
  x = new double[3*n];
  w = new double[n];

  cube_arbq ( degree, n, x, w );

  cout << "\n";
  cout << "  Number of nodes N = " << n << "\n";

  cout << "\n";
  cout << "     J  W       X       Y      Z\n";
  cout << "\n";
  for ( j = 0; j < n; j++ )
  {
    cout << "  %4d  %14.6g  %14.6g  %14.6g  %14.6g\n",
      j, w[j], x[0+j*3], x[1+j*3], x[2+j*3] );
  }

  d = r8vec_sum ( n, w );

  cout << "   Sum    " << d << "\n";
  cout << "  Volume  " << volume << "\n";

  return;
}
//****************************************************************************80

void test02 ( int degree, int n, string header )

//****************************************************************************80
/*
  Purpose:

    TEST02 gets a rule and writes it to a file.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    09 July 2014

  Author:

    Original FORTRAN77 version by Hong Xiao, Zydrunas Gimbutas.
    This C++ version by John Burkardt.

  Reference:

    Hong Xiao, Zydrunas Gimbutas,
    A numerical algorithm for the construction of efficient quadrature
    rules in two and higher dimensions,
    Computers and Mathematics with Applications,
    Volume 59, 2010, pages 663-676.

  Parameters:

    Input, int DEGREE, the desired total polynomial degree exactness
    of the quadrature rule.  0 <= DEGREE <= 50.

    Input, int N, the number of nodes to be used by the rule.

    Input, string HEADER, an identifier for the filenames.
*/
{
  int i;
  ofstream rule_unit;
  string rule_filename;
  double *w;
  double *x;

  cout << "\n";
  cout << "TEST02\n";
  cout << "  Get a quadrature rule for the symmetric cube.\n";
  cout << "  Then write it to a file.\n";
  cout << "  Polynomial exactness degree DEGREE = " << degree << "\n";
/*
  Retrieve a symmetric quadrature rule.
*/
  x = new double[3*n];
  w = new double[n];

  cube_arbq ( degree, n, x, w );
/*
  Write the points and weights to a file.
*/
  rule_filename = header + ".txt";

  rule_unit.open ( rule_filename,c_str ( ) );
  for ( i = 0; i < n; i++ )
  {
    fcout << rule_unit, "%g  %g  %g  %g\n", x[0+i*3], x[1+i*3], x[2+i*3], w[i] );
  }
  rule_unit.close ( );
  cout << "\n";
  cout << "  Quadrature rule written to file '" << rule_filename << "'\n";

  free ( w );
  free ( x );

  return;
}
//****************************************************************************80

void test03 ( int degree, int n, string header )

//****************************************************************************80
/*
  Purpose:

    TEST03 gets a rule and creates GNUPLOT input files.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    09 July 2014

  Author:

    Original FORTRAN77 version by Hong Xiao, Zydrunas Gimbutas.
    This C++ version by John Burkardt.

  Reference:

    Hong Xiao, Zydrunas Gimbutas,
    A numerical algorithm for the construction of efficient quadrature
    rules in two and higher dimensions,
    Computers and Mathematics with Applications,
    Volume 59, 2010, pages 663-676.

  Parameters:

    Input, int DEGREE, the desired total polynomial degree exactness
    of the quadrature rule.  0 <= DEGREE <= 50.

    Input, int N, the number of nodes to be used by the rule.

    Input, string HEADER, an identifier for the filenames.
*/
{
  double *w;
  double *x;

  cout << "\n";
  cout << "TEST03\n";
  cout << "  Get a quadrature rule for the symmetric cube.\n";
  cout << "  Set up GNUPLOT graphics input.\n";
  cout << "  Polynomial exactness degree DEGREE = " << degree << "\n";
/*
  Retrieve a symmetric quadrature rule.
*/
  x = new double[3*n];
  w = new double[n];

  cube_arbq ( degree, n, x, w );
/*
  Create files for input to GNUPLOT.
*/
  cube_arbq_gnuplot ( n, x, header );

  free ( w );
  free ( x );

  return;
}
//****************************************************************************80

void test04 ( int degree, int n )

//****************************************************************************80
/*
  Purpose:

    TEST04 gets a rule and tests its accuracy.

  Licensing:

    This code is distributed under the GNU GPL license.

  Modified:

    09 July 2014

  Author:

    Original FORTRAN77 version by Hong Xiao, Zydrunas Gimbutas.
    This C++ version by John Burkardt.

  Reference:

    Hong Xiao, Zydrunas Gimbutas,
    A numerical algorithm for the construction of efficient quadrature
    rules in two and higher dimensions,
    Computers and Mathematics with Applications,
    Volume 59, 2010, pages 663-676.

  Parameters:

    Input, int DEGREE, the desired total polynomial degree exactness
    of the quadrature rule.  0 <= DEGREE <= 50.

    Input, int N, the number of nodes to be used by the rule.
*/
{
  double d;
  int i;
  int j;
  int npols;
  double *pols;
  double *rints;
  double volume;
  double *w;
  double *x;
  double z[3];

  cout << "\n";
  cout << "TEST04\n";
  cout << "  Get a quadrature rule for the symmetric cube.\n";
  cout << "  Test its accuracy.\n";
  cout << "  Polynomial exactness degree DEGREE = " << degree << "\n";
/*
  Retrieve a symmetric quadrature rule.
*/
  x = new double[3*n];
  w = new double[n];

  cube_arbq ( degree, n, x, w );

  npols = ( ( degree + 1 ) * ( degree + 2 ) * ( degree + 3 ) ) / 6;
  rints = ( double * ) malloc ( npols * sizeof ( double ) );

  for ( j = 0; j < npols; j++ )
  {
    rints[j] = 0.0;
  }

  for ( i = 0; i < n; i++ )
  {
    z[0] = x[0+i*3];
    z[1] = x[1+i*3];
    z[2] = x[2+i*3];

    pols = lege3eva ( degree, z );
    for ( j = 0; j < npols; j++ )
    {
      rints[j] = rints[j] + w[i] * pols[j];
     }
    free ( pols );
  }

  volume = 8.0;

  d = 0.0;
  d = pow ( rints[0] - sqrt ( volume ), 2 );
  for ( i = 1; i < npols; i++ )
  {
    d = d + pow ( rints[i], 2 );
  }
  d = sqrt ( d ) / ( double ) ( npols );

  cout << "\n";
  cout << "  RMS error = %g\n", d );

  free ( rints );
  free ( w );
  free ( x );

  return;
}
