# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "circle_monte_carlo.hpp"

//****************************************************************************80

double circle01_length ( )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCLE01_LENGTH: length of the circumference of the unit circle in 2D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 January 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double CIRCLE01_LENGTH, the length.
//
{
  double length;
  const double r = 1.0;
  const double r8_pi = 3.141592653589793;

  length = 2.0 * r8_pi * r;

  return length;
}
//****************************************************************************80

double circle01_monomial_integral ( int e[2] )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCLE01_MONOMIAL_INTEGRAL returns monomial integrals on the unit circle.
//
//  Discussion:
//
//    The integration region is 
//
//      X^2 + Y^2 = 1.
//
//    The monomial is F(X,Y) = X^E(1) * Y^E(2).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 January 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Philip Davis, Philip Rabinowitz,
//    Methods of Numerical Integration,
//    Second Edition,
//    Academic Press, 1984, page 263.
//
//  Parameters:
//
//    Input, int E[2], the exponents of X and Y in the 
//    monomial.  Each exponent must be nonnegative.
//
//    Output, double CIRCLE01_MONOMIAL_INTEGRAL, the integral.
//
{
  double arg;
  int i;
  double integral;

  if ( e[0] < 0 || e[1] < 0 )
  {
    cout << "\n";
    cout << "CIRCLE01_MONOMIAL_INTEGRAL - Fatal error!\n";
    cout << "  All exponents must be nonnegative.\n";
    cout << "  E[0] = " << e[0] << "\n";
    cout << "  E[1] = " << e[1] << "\n";
    exit ( 1 );
  }

  if ( ( e[0] % 2 ) == 1 || ( e[1] % 2 ) == 1 )
  {
    integral = 0.0;
  }
  else
  {
    integral = 2.0;

    for ( i = 0; i < 2; i++ )
    {
      arg = 0.5 * ( double ) ( e[i] + 1 );
      integral = integral * r8_gamma ( arg );
    }

    arg = 0.5 * ( double ) ( e[0] + e[1] + 2 );
    integral = integral / r8_gamma ( arg );
  }
  return integral;
}
//****************************************************************************80

double *circle01_sample_ergodic ( int n, double &angle )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCLE01_SAMPLE_ERGODIC samples the circumference of the unit circle in 2D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    06 June 2017
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Russell Cheng,
//    Random Variate Generation,
//    in Handbook of Simulation,
//    edited by Jerry Banks,
//    Wiley, 1998, pages 168.
//
//    Reuven Rubinstein,
//    Monte Carlo Optimization, Simulation, and Sensitivity 
//    of Queueing Networks,
//    Krieger, 1992,
//    ISBN: 0894647644,
//    LC: QA298.R79.
//
//  Parameters:
//
//    Input, int N, the number of points.
//
//    Input/output, double ANGLE, the base angle, which could be anything
//    in the range [0,2 PI).
//
//    Output, double X[2*N], the points.
//
{
  const double c[2] = { 0.0, 0.0 };
  double golden_angle;
  double golden_ratio;
  int j;
  const double r = 1.0;
  const double r8_pi = 3.141592653589793;
  double *x;

  golden_ratio = ( 1.0 + sqrt ( 5.0 ) ) / 2.0;

  golden_angle = 2.0 * r8_pi / pow ( golden_ratio, 2 );

  x = ( double * ) malloc ( 2 * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    x[0+j*2] = c[0] + r * cos ( angle );
    x[1+j*2] = c[1] + r * sin ( angle );
    angle = fmod ( angle + golden_angle, 2.0 * r8_pi ) ;
  }

  return x;
}
//****************************************************************************80

double *circle01_sample_random ( int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCLE01_SAMPLE_RANDOM samples the circumference of the unit circle in 2D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    06 June 2017
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Russell Cheng,
//    Random Variate Generation,
//    in Handbook of Simulation,
//    edited by Jerry Banks,
//    Wiley, 1998, pages 168.
//
//    Reuven Rubinstein,
//    Monte Carlo Optimization, Simulation, and Sensitivity 
//    of Queueing Networks,
//    Krieger, 1992,
//    ISBN: 0894647644,
//    LC: QA298.R79.
//
//  Parameters:
//
//    Input, int N, the number of points.
//
//    Input/output, int &SEED, a seed for the random 
//    number generator.
//
//    Output, double X[2*N], the points.
//
{
  const double c[2] = { 0.0, 0.0 };
  int i;
  int j;
  const double r = 1.0;
  const double r8_pi = 3.141592653589793;
  double *theta;
  double *x;

  theta = r8vec_uniform_01_new ( n, seed );

  x = new double[2*n];

  for ( j = 0; j < n; j++ )
  {
    x[0+j*2] = c[0] + r * cos ( 2.0 * r8_pi * theta[j] );
    x[1+j*2] = c[1] + r * sin ( 2.0 * r8_pi * theta[j] );
  }

  delete [] theta;

  return x;
}
//****************************************************************************80

double *monomial_value ( int m, int n, int e[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    MONOMIAL_VALUE evaluates a monomial.
//
//  Discussion:
//
//    This routine evaluates a monomial of the form
//
//      product ( 1 <= i <= m ) x(i)^e(i)
//
//    where the exponents are nonnegative integers.  Note that
//    if the combination 0^0 is encountered, it should be treated
//    as 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 May 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the spatial dimension.
//
//    Input, int N, the number of points at which the
//    monomial is to be evaluated.
//
//    Input, int E[M], the exponents.
//
//    Input, double X[M*N], the point coordinates.
//
//    Output, double MONOMIAL_VALUE[N], the value of the monomial.
//
{
  int i;
  int j;
  double *v;

  v = new double[n];

  for ( j = 0; j < n; j++ )
  {
    v[j] = 1.0;
  }

  for ( i = 0; i < m; i++ )
  {
    if ( 0 != e[i] )
    {
      for ( j = 0; j < n; j++ )
      {
        v[j] = v[j] * pow ( x[i+j*m], e[i] );
      }
    }
  }

  return v;
}
//****************************************************************************80

double r8_gamma ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    R8_GAMMA evaluates Gamma(X) for a real argument.
//
//  Discussion:
//
//    The C MATH library includes a function GAMMA ( X ) which should be
//    invoked instead of this function.
//
//    This routine calculates the gamma function for a real argument X.
//
//    Computation is based on an algorithm outlined in reference 1.
//    The program uses rational functions that approximate the gamma
//    function to at least 20 significant decimal digits.  Coefficients
//    for the approximation over the interval (1,2) are unpublished.
//    Those for the approximation for 12 <= X are from reference 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 January 2008
//
//  Author:
//
//    Original FORTRAN77 version by William Cody, Laura Stoltz.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    William Cody,
//    An Overview of Software Development for Special Functions,
//    in Numerical Analysis Dundee, 1975,
//    edited by GA Watson,
//    Lecture Notes in Mathematics 506,
//    Springer, 1976.
//
//    John Hart, Ward Cheney, Charles Lawson, Hans Maehly,
//    Charles Mesztenyi, John Rice, Henry Thatcher,
//    Christoph Witzgall,
//    Computer Approximations,
//    Wiley, 1968,
//    LC: QA297.C64.
//
//  Parameters:
//
//    Input, double X, the argument of the function.
//
//    Output, double R8_GAMMA, the value of the function.
//
{
  double c[7] = {
   -1.910444077728E-03, 
    8.4171387781295E-04, 
   -5.952379913043012E-04, 
    7.93650793500350248E-04, 
   -2.777777777777681622553E-03, 
    8.333333333333333331554247E-02, 
    5.7083835261E-03 };
  double eps = 2.22E-16;
  double fact;
  int i;
  int n;
  double p[8] = {
  -1.71618513886549492533811E+00,
   2.47656508055759199108314E+01, 
  -3.79804256470945635097577E+02,
   6.29331155312818442661052E+02, 
   8.66966202790413211295064E+02,
  -3.14512729688483675254357E+04, 
  -3.61444134186911729807069E+04,
   6.64561438202405440627855E+04 };
  bool parity;
  double pi = 3.1415926535897932384626434;
  double q[8] = {
  -3.08402300119738975254353E+01,
   3.15350626979604161529144E+02, 
  -1.01515636749021914166146E+03,
  -3.10777167157231109440444E+03, 
   2.25381184209801510330112E+04,
   4.75584627752788110767815E+03, 
  -1.34659959864969306392456E+05,
  -1.15132259675553483497211E+05 };
  double res;
  double sqrtpi = 0.9189385332046727417803297;
  double sum;
  double value;
  double xbig = 171.624;
  double xden;
  double xinf = 1.79E+308;
  double xminin = 2.23E-308;
  double xnum;
  double y;
  double y1;
  double ysq;
  double z;

  parity = false;
  fact = 1.0;
  n = 0;
  y = x;
//
//  Argument is negative.
//
  if ( y <= 0.0 )
  {
    y = - x;
    y1 = ( double ) ( int ) ( y );
    res = y - y1;

    if ( res != 0.0 )
    {
      if ( y1 != ( double ) ( int ) ( y1 * 0.5 ) * 2.0 )
      {
        parity = true;
      }

      fact = - pi / sin ( pi * res );
      y = y + 1.0;
    }
    else
    {
      res = xinf;
      value = res;
      return value;
    }
  }
//
//  Argument is positive.
//
  if ( y < eps )
  {
//
//  Argument < EPS.
//
    if ( xminin <= y )
    {
      res = 1.0 / y;
    }
    else
    {
      res = xinf;
      value = res;
      return value;
    }
  }
  else if ( y < 12.0 )
  {
    y1 = y;
//
//  0.0 < argument < 1.0.
//
    if ( y < 1.0 )
    {
      z = y;
      y = y + 1.0;
    }
//
//  1.0 < argument < 12.0.
//  Reduce argument if necessary.
//
    else
    {
      n = ( int ) ( y ) - 1;
      y = y - ( double ) ( n );
      z = y - 1.0;
    }
//
//  Evaluate approximation for 1.0 < argument < 2.0.
//
    xnum = 0.0;
    xden = 1.0;
    for ( i = 0; i < 8; i++ )
    {
      xnum = ( xnum + p[i] ) * z;
      xden = xden * z + q[i];
    }
    res = xnum / xden + 1.0;
//
//  Adjust result for case  0.0 < argument < 1.0.
//
    if ( y1 < y )
    {
      res = res / y1;
    }
//
//  Adjust result for case 2.0 < argument < 12.0.
//
    else if ( y < y1 )
    {
      for ( i = 1; i <= n; i++ )
      {
        res = res * y;
        y = y + 1.0;
      }
    }
  }
  else
  {
//
//  Evaluate for 12.0 <= argument.
//
    if ( y <= xbig )
    {
      ysq = y * y;
      sum = c[6];
      for ( i = 0; i < 6; i++ )
      {
        sum = sum / ysq + c[i];
      }
      sum = sum / y - y + sqrtpi;
      sum = sum + ( y - 0.5 ) * log ( y );
      res = exp ( sum );
    }
    else
    {
      res = xinf;
      value = res;
      return value;
    }
  }
//
//  Final adjustments and return.
//
  if ( parity )
  {
    res = - res;
  }

  if ( fact != 1.0 )
  {
    res = fact / res;
  }

  value = res;

  return value;
}
//****************************************************************************80

double r8vec_sum ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_SUM returns the sum of an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 October 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input, double A[N], the vector.
//
//    Output, double R8VEC_SUM, the sum of the vector.
//
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a[i];
  }
  return value;
}
//****************************************************************************80

double *r8vec_uniform_01_new ( int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_01_NEW returns a new unit pseudorandom R8VEC.
//
//  Discussion:
//
//    This routine implements the recursion
//
//      seed = ( 16807 * seed ) mod ( 2^31 - 1 )
//      u = seed / ( 2^31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Second Edition,
//    Springer, 1987,
//    ISBN: 0387964673,
//    LC: QA76.9.C65.B73.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, December 1986, pages 362-376.
//
//    Pierre L'Ecuyer,
//    Random Number Generation,
//    in Handbook of Simulation,
//    edited by Jerry Banks,
//    Wiley, 1998,
//    ISBN: 0471134031,
//    LC: T57.62.H37.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, Number 2, 1969, pages 136-143.
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input/output, int &SEED, a seed for the random number generator.
//
//    Output, double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
//
{
  int i;
  int i4_huge = 2147483647;
  int k;
  double *r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8VEC_UNIFORM_01_NEW - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  r = new double[n];

  for ( i = 0; i < n; i++ )
  {
    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )
    {
      seed = seed + i4_huge;
    }

    r[i] = ( double ) ( seed ) * 4.656612875E-10;
  }

  return r;
}
//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//
//  Purpose:
//
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
//  Example:
//
//    31 May 2001 09:45:54 AM
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    None
//
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  size_t len;
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  len = std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
