#include "Helper.hpp"
#include <cmath>

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
long long Helper::digits(long long x)
{
	/*********** INSERT YOUR CODE HERE ****************/
  if (x < 10){
    return 1;
  }

  long long  count = 0; 
  while (x > 0){
    x /= 10;
    count++;
  }
  return count;
}

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
void Helper::split(long long x, long long digit, long long &high, long long &low)
{
	/*********** INSERT YOUR CODE HERE ****************/
  long long div = static_cast<long long>(pow(10,digit));
  low = x%div;
  high = x/div;
}
