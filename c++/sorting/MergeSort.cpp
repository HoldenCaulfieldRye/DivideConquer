#include "MergeSort.hpp"
#include <iostream>
#include <limits.h>

void MergeSort::sort(std::vector<int> &A)
{
	sortpart(A, 0, static_cast<int>(A.size())-1);
}

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
void MergeSort::sortpart(std::vector<int> &A, int p, int r)
{
  if (p < r) {
    int q = (p+r)/2;
    sortpart(A, p, q);
    sortpart(A, q+1, r);
    merge(A, p, q, r);
  }
}

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
void MergeSort::merge(std::vector<int> &A, int p, int q, int r)
{
  //could copy to a vector, but a static array is faster
  //(faster than a dynamic array - because accessing heap is slower?)
  //(or because static array destroyed after timer stops?)
  int copyOfA[r+1];
  for(int k = p; k<=r; k++)
    copyOfA[k] = A[k];

  int n=p, a=p, b=q+1;
  
  while (a<=q && b<=r) {
    if (copyOfA[a] <= copyOfA[b]) {
      A[n] = copyOfA[a];
      a++, n++;
    }
    else {
      A[n] = copyOfA[b];
      b++, n++;
    }
  }
  
  //reach here once one of the two arrays is spent. just need to insert in same order what's
  //left in the other.
  while (a<=q) {
    A[n] = copyOfA[a];
    a++, n++;
  }
  while (b<=r) {
    A[n] = copyOfA[b];
    b++, n++;
  }
}
