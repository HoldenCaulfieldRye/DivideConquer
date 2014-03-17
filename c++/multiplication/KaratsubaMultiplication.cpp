#include "KaratsubaMultiplication.hpp"
#include "Helper.hpp"
#include <cmath>

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
long long KaratsubaMultiplication::multiply(long long x, long long y)
{
	/*********** INSERT YOUR CODE HERE ****************/
  long long x_len = Helper::digits(x);
  long long  y_len = Helper::digits(y);
  if (x_len == 1 || y_len == 1)
    return x*y;
  
  long long no_digits = 0;
  if (x > y)
    no_digits = x_len;
   else
     no_digits = y_len;
  
  long long digit = no_digits/2;
  long long Lx = 0, Rx = 0, Ly = 0, Ry = 0;
  Helper::split(x, digit, Lx, Rx);
  Helper::split(y, digit, Ly, Ry);
  
  long long x1 = multiply(Rx,Ry);
  long long x2 = multiply((Lx+Rx), (Ly+Ry));
  long long x3 = multiply(Lx, Ly);
  
  return (x3*static_cast<long long>(pow(10,digit*2))) + ((x2-x3-x1)*static_cast<long long>(pow(10,digit))) + x1;
}
