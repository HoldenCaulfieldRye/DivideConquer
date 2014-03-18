#include "HybridSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include <iostream>

void HybridSort::sort(std::vector<int> &A)
{
  sortpart(A, 0, static_cast<int>(A.size())-1);
}

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
void HybridSort::sortpart(std::vector<int> &A, int p, int r)
{ 
  if (r-p+1 <= 4) {
    if (A[p] > A[r]) {
      int temp = A[p];
      A[p] = A[r];
      A[r] = temp;
    }
  }
  else {
    int q = (p+r)/2;
    HybridSort::sortpart(A, p, q);
    HybridSort::sortpart(A, q+1, r);
    MergeSort::merge(A, p, q, r);
  }  
}
