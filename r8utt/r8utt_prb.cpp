# include <cmath>
# include <iomanip>
# include <iostream>

using namespace std;

# include "r8utt.hpp"

int main ( );
void r8utt_det_test ( );
void r8utt_indicator_test ( );
void r8utt_inverse_test ( );
void r8utt_mm_test ( );
void r8utt_mtm_test ( );
void r8utt_mtv_test ( );
void r8utt_mv_test ( );
void r8utt_print_test ( );
void r8utt_print_some_test ( );
void r8utt_random_test ( );
void r8utt_sl_test ( );
void r8utt_slt_test ( );
void r8utt_to_r8ge_test ( );
void r8utt_zeros_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for R8UTT_PRB.
//
//  Discussion:
//
//    R8UTT_PRB tests the R8UTT library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "R8UTT_PRB\n";
  cout << "  C++ version\n";
  cout << "  Test the R8UTT library.\n";

  r8utt_det_test ( );
  r8utt_indicator_test ( );
  r8utt_inverse_test ( );
  r8utt_mm_test ( );
  r8utt_mtm_test ( );
  r8utt_mtv_test ( );
  r8utt_mv_test ( );
  r8utt_print_test ( );
  r8utt_print_some_test ( );
  r8utt_random_test ( );
  r8utt_sl_test ( );
  r8utt_slt_test ( );
  r8utt_to_r8ge_test ( );
  r8utt_zeros_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "R8UTT_PRB\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void r8utt_det_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_DET_TEST tests R8UTT_DET.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double det;
  int i;
  int j;
  int n = 5;
  int seed = 123456789;

  cout << "\n";
  cout << "R8UTT_DET_TEST\n";
  cout << "  R8UTT_DET computes the determinant of an R8UTT matrix.\n";

  a = r8utt_random ( n, seed );

  r8utt_print ( n, a, "  The matrix A:" );
//
//  Compute the determinant.
//
  det = r8utt_det ( n, a );

  cout << "\n";
  cout << "  Determinant is " << det << "\n";

  delete [] a;

  return;
}
//****************************************************************************80

void r8utt_indicator_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_INDICATOR_TEST tests R8UTT_INDICATOR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  int n = 5;

  cout << "\n";
  cout << "R8UTT_INDICATOR_TEST\n";
  cout << "  R8UTT_INDICATOR sets up an indicator matrix in R8UTT format\n";
  cout << "\n";
  cout << "  Matrix order N = " << n << "\n";

  a = r8utt_indicator ( n );

  r8utt_print ( n, a, "  The indicator matrix:" );

  delete [] a;

  return;
}
//****************************************************************************80

void r8utt_inverse_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_INVERSE_TEST tests R8UTT_INVERSE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double *b;
  double *c;
  int n = 5;
  int seed;

  seed = 123456789;

  cout << "\n";
  cout << "R8UTT_INVERSE_TEST\n";
  cout << "  R8UTT_INVERSE computes the inverse of an R8UTT matrix.\n";

  a = r8utt_random ( n, seed );

  r8utt_print ( n, a, "  The matrix A:" );
//
//  Compute the inverse matrix B.
//
  b = r8utt_inverse ( n, a );

  r8utt_print ( n, b, "  The inverse matrix B:" );
//
//  Check
//
  c = r8utt_mm ( n, a, b );

  r8utt_print ( n, c, "  The product A * B:" );

  delete [] a;
  delete [] b;
  delete [] c;

  return;
}
//****************************************************************************80

void r8utt_mm_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_MM_TEST tests R8UTT_MM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double *a_ge;
  double *b;
  double *b_ge;
  double *c;
  double *c_ge;
  int n = 5;
  int seed;

  cout << "\n";
  cout << "R8UTT_MM_TEST\n";
  cout << "  R8UTT_MM computes C = A * B for R8UTT matrices.\n";
  cout << "\n";
  cout << "  Matrix order N = " << n << "\n";

  seed = 123456789;
  a = r8utt_random ( n, seed );
  r8utt_print ( n, a, "  Factor A:" );
  b = r8utt_random ( n, seed );
  r8utt_print ( n, b, "  Factor B:" );
  c = r8utt_mm ( n, a, b );
  r8utt_print ( n, c, "  The product C = A * B" );

  a_ge = r8utt_to_r8ge ( n, a );
  b_ge = r8utt_to_r8ge ( n, b );
  c_ge = r8ge_mm ( n, a_ge, b_ge );
  r8ge_print ( n, n, c_ge, "  The R8GE product C:" );

  delete [] a;
  delete [] a_ge;
  delete [] b;
  delete [] b_ge;
  delete [] c;
  delete [] c_ge;

  return;
}
//****************************************************************************80

void r8utt_mtm_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_MTM_TEST tests R8UTT_MTM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double *a_ge;
  double *b;
  double *b_ge;
  double *c_ge;
  int n = 5;
  int seed;

  seed = 123456789;

  cout << "\n";
  cout << "R8UTT_MTM_TEST\n";
  cout << "  R8UTT_MTM computes C = A' * B for R8UTT matrices.\n";

  a = r8utt_random ( n, seed );
  r8utt_print ( n, a, "  The matrix A:" );
  b = r8utt_random ( n, seed );
  r8utt_print ( n, b, "  The matrix B:" );

  c_ge = r8utt_mtm ( n, a, b );
  r8ge_print ( n, n, c_ge, "  The product C = A' * B:" );
  delete [] c_ge;
//
//  Compare with an R8GE calculation.
//
  a_ge = r8utt_to_r8ge ( n, a );
  b_ge = r8utt_to_r8ge ( n, b );
  c_ge = r8ge_mtm ( n, a_ge, b_ge );
  r8ge_print ( n, n, c_ge, "  The R8GE product C = A' * B:" );

  delete [] a;
  delete [] a_ge;
  delete [] b;
  delete [] b_ge;
  delete [] c_ge;

  return;
}
//****************************************************************************80

void r8utt_mtv_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_MTV_TEST tests R8UTT_MTV.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double *b;
  int n = 5;
  double *x;

  cout << "\n";
  cout << "R8UTT_MTV_TEST\n";
  cout << "  R8UTT_MTV computes a matrix product b=A'*x for an R8UTT matrix.\n";
  cout << "\n";
  cout << "  Matrix order N = " << n << "\n";

  a = r8utt_indicator ( n );
  r8utt_print ( n, a, "  The matrix A:" );

  x = r8vec_indicator1_new ( n );
  r8vec_print ( n, x, "  The vector X:" );

  b = r8utt_mtv ( n, a, x );
  r8vec_print ( n, b, "  The vector b=A'*x:" );

  delete [] a;
  delete [] b;
  delete [] x;

  return;
}
//****************************************************************************80

void r8utt_mv_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_MV_TEST tests R8UTT_MV
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double *b;
  int n = 5;
  double *x;

  cout << "\n";
  cout << "R8UTT_MV_TEST\n";
  cout << "  R8UTT_MV computes a product b=A*x for an R8UTT matrix.\n";
  cout << "\n";
  cout << "  Matrix order N = " << n << "\n";

  a = r8utt_indicator ( n );
  r8utt_print ( n, a, "  The R8UTT matrix A:" );

  x = r8vec_indicator1_new ( n );
  r8vec_print ( n, x, "  Vector x:" );

  b = r8utt_mv ( n, a, x );
  r8vec_print ( n, b, "  Vector b = A*x:" );

  delete [] a;
  delete [] b;
  delete [] x;

  return;
}
//****************************************************************************80

void r8utt_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_PRINT_TEST tests R8UTT_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  int n = 5;

  cout << "\n";
  cout << "R8UTT_PRINT_TEST\n";
  cout << "  R8UTT_PRINT prints an R8UTT matrix.\n";
  cout << "\n";
  cout << "  Matrix order N = " << n << "\n";

  a = r8utt_indicator ( n );

  r8utt_print ( n, a, "  The matrix:" );

  delete [] a;

  return;
}
//****************************************************************************80

void r8utt_print_some_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_PRINT_SOME_TEST tests R8UTT_PRINT_SOME.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  int n = 5;

  cout << "\n";
  cout << "R8UTT_PRINT_SOME_TEST\n";
  cout << "  R8UTT_PRINT_SOME prints some of an R8UTT matrix.\n";
  cout << "\n";
  cout << "  Matrix order N = " << n << "\n";

  a = r8utt_indicator ( n );

  r8utt_print_some ( n, a, 1, 4, 3, 6, "  Some of the matrix:" );

  delete [] a;

  return;
}
//****************************************************************************80

void r8utt_random_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_RANDOM_TEST tests R8UTT_RANDOM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  int n;
  int seed;

  n = 5;
  seed = 123456789;

  cout << "\n";
  cout << "R8UTT_RANDOM_TEST\n";
  cout << "  R8UTT_RANDOM randomizes an R8UTT matrix.\n";
  cout << "\n";
  cout << "  Matrix order N = " << n << "\n";

  a = r8utt_random ( n, seed );

  r8utt_print ( n, a, "  Matrix A:" );

  delete [] a;

  return;
}
//****************************************************************************80

void r8utt_sl_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_SL_TEST tests R8UTT_SL.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double *b;
  int n = 5;
  int seed;
  double *x;

  cout << "\n";
  cout << "R8UTT_SL_TEST\n";
  cout << "  R8UTT_SL solves a linear system A*x=b with R8UTT matrix\n";
  cout << "\n";
  cout << "  Matrix order N = " << n << "\n";

  seed = 123456789;
  a = r8utt_random ( n, seed );

  r8utt_print ( n, a, "  Matrix A:" );
//
//  Set the desired solution.
//
  x = r8vec_indicator1_new ( n );
//
//  Compute the corresponding right hand side.
//
  b = r8utt_mv ( n, a, x );
  r8vec_print ( n, b, "  Right hand side b:" );
//
//  Solve the linear system.
//
  x = r8utt_sl ( n, a, b );

  r8vec_print ( n, x, "  Solution x:" );

  delete [] a;
  delete [] b;
  delete [] x;

  return;
}
//****************************************************************************80

void r8utt_slt_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_SLT_TEST tests R8UTT_SLT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double *b;
  int n = 5;
  int seed;
  double *x;

  cout << "\n";
  cout << "R8UTT_SLT_TEST\n";
  cout << "  R8UTT_SLT solves a linear system A'x=b with R8UTT matrix\n";
  cout << "\n";
  cout << "  Matrix order N = " << n << "\n";

  seed = 123456789;
  a = r8utt_random ( n, seed );

  r8utt_print ( n, a, "  Matrix A:" );
//
//  Set the desired solution.
//
  x = r8vec_indicator1_new ( n );
//
//  Compute the corresponding right hand side.
//
  b = r8utt_mtv ( n, a, x );

  r8vec_print ( n, b, "  Right hand side b:" );
//
//  Solve the linear system.
//
  x = r8utt_slt ( n, a, b );

  r8vec_print ( n, x, "  Solution x:" );

  delete [] a;
  delete [] b;
  delete [] x;

  return;
}
//****************************************************************************80

void r8utt_to_r8ge_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_TO_R8GE_TEST tests R8UTT_TO_R8GE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a_ge;
  double *a_utt;
  int n;
  int seed;

  n = 5;
  seed = 123456789;

  cout << "\n";
  cout << "R8UTT_TO_R8GE_TEST\n";
  cout << "  R8UTT_TO_R8GE converts an R8UTT matrix to R8GE format.\n";

  a_utt = r8utt_random ( n, seed );

  r8utt_print ( n, a_utt, "  R8UTT matrix:" );

  a_ge = r8utt_to_r8ge ( n, a_utt );

  r8ge_print ( n, n, a_ge, "  R8GE matrix" );

  delete [] a_ge;
  delete [] a_utt;

  return;
}
//****************************************************************************80

void r8utt_zeros_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8UTT_ZEROS_TEST tests R8UTT_ZEROS.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 November 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  int n = 5;

  cout << "\n";
  cout << "R8UTT_ZEROS_TEST\n";
  cout << "  R8UTT_ZEROS returns a zeroed out R8UTT matrix.\n";
  cout << "\n";
  cout << "  Matrix order N = " << n << "\n";

  a = r8utt_zeros ( n );

  r8utt_print ( n, a, "  Matrix A:" );

  delete [] a;

  return;
}
