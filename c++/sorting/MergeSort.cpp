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

  int n=p, a=p, b=q+1;
  while (a<=q && b<=r) {
    if (copyOfA[a] <= copyOfA[b]) {
      A[n] = copyOfA[a];
      a++, n++;
      std::cout << "sorted " << copyOfA[a-1] << ". array now:" << std::endl;
      for(int k = p; k<=r; k++)
	std::cout << A[k] << ' ';
      std::cout << std::endl;
    }
    else {
      A[n] = copyOfA[b];
      b++, n++;
      std::cout << "sorted " << copyOfA[b-1] << ". array now:" << std::endl;
      for(int k = p; k<=r; k++)
	std::cout << A[k] << ' ';
      std::cout << std::endl;
    }
  }
  
  while (a<=q) {
    A[n] = copyOfA[a];
    a++, n++;
      std::cout << "sorted " << copyOfA[a-1] << ". array now:" << std::endl;
      for(int k = p; k<=r; k++)
	std::cout << A[k] << ' ';
      std::cout << std::endl;
  }
  
  while (b<=r) {
    A[n] = copyOfA[b];
    b++, n++;
      std::cout << "sorted " << copyOfA[b-1] << ". array now:" << std::endl;
      for(int k = p; k<=r; k++)
	std::cout << A[k] << ' ';
      std::cout << std::endl;
  }
}
