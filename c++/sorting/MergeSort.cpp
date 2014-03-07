#include "MergeSort.hpp"
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
  //A[p:q] is sorted, A[q+1:r] is sorted, latter array might have size one greater
  int temp[2];
  for (int i=0; i<=q-p; i++) { //i<q-p+1?
    if (A[p+i] <= A[q+1+i]) {
      temp[0] = A[p+i+1];   //ok but when will temp[0] be reinserted?
      A[p+i+1] = A[q+1+i];
    }
    else {
      temp[0] = A[p+i];
      A[p+i] = A[q+1+i];
      temp[1] = A[p+i+1];   //ok but when will temp[1] be reinserted?
      A[p+i+1] = temp[0];
    }
  }

  if ((p+r) % 2 == 1) { //if A[q+1:r] has size 1 more than A[p:q]

  }
}
