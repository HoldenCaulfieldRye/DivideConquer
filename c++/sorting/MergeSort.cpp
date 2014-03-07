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
  std::cout << "have just been given this to merge: " << std::endl;
  for(int k = p; k<=r; k++)
    std::cout << A[k] << ' ';
  std::cout << std::endl; 
  //A[p:q] is sorted, A[q+1:r] is sorted, A[p:q] has size one greater
  std::vector<int> copyOfA(A);

  
  for (int i=0; i<=r-q-1; i++) { 
    if (copyOfA[p+i] <= copyOfA[q+1+i]) {
      A[p+(2*i)] = copyOfA[p+i];
      A[p+(2*i)+1] = copyOfA[q+1+i];  //A[p+i] in its right place
    }
    else {
      A[p+(2*i)] = copyOfA[q+1+i];
      A[p+(2*i)+1] = copyOfA[p+i];
    }

    
    std::cout << "sorted " << copyOfA[p+i] << ", " << copyOfA[q+1+i] << ". array now:" << std::endl;
    for(int k = p; k<=r; k++)
      std::cout << A[k] << ' ';
    std::cout << std::endl;
  }

  
  if ((p+r) % 2 == 0) { //if A[p:q] has size 1 more than A[q+1:r]
    if (A[r] > copyOfA[q])
      A[r-1] = copyOfA[q];
    else A[r] = copyOfA[q];

    
    std::cout << "sorted " << copyOfA[q] << ". array now:" << std::endl;
    for(int k = p; k<=r; k++)
      std::cout << A[k] << ' ';
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
