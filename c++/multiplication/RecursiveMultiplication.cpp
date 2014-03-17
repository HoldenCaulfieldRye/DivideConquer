#include "RecursiveMultiplication.hpp"
#include "Helper.hpp"
#include <cmath>
#include <iomanip>

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
long long RecursiveMultiplication::multiply(long long x, long long y)
{
	/*********** INSERT YOUR CODE HERE ****************/
  if (Helper::digits(x) == 1 || Helper::digits(y) == 1)
    return x*y;
  
  long long  no_digits = 0;
  if (x > y)
    no_digits = Helper::digits(x);
  else
    no_digits = Helper::digits(y);

  long long  digit = no_digits/2;
  long long Lx = 0, Rx = 0, Ly = 0, Ry = 0;
  Helper::split(x, digit, Lx, Rx);
  Helper::split(y, digit, Ly, Ry);
  
  long long x1 = multiply(Lx, Ly);
  long long x2 = multiply(Lx, Ry);
  long long x3 = multiply(Rx, Ly);
  long long x4 = multiply(Rx, Ry);

  return (x1*static_cast<long long>(pow(10, digit*2))) + ((x2+x3)*static_cast<long long>(pow(10,digit))) + x4;			 
}
