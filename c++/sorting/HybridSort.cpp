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
  if (r - p <= 8) {
    // std::cout << "using insertion to sort ";
    // for(int k = p; k<=r; k++)
    //   std::cout << A[k] << ' ';
    // std::cout << std::endl;

    for (int j=p+1; j<=r; j++) {
      int key = A[j];
      int i = j-1;
      while (i>=0 && A[i] > key) {
	A[i+1] = A[i];
	i--;
      }
      A[i+1] = key;
    }
  }
  else {
    int q = (p+r)/2;
    HybridSort::sortpart(A, p, q);   //HybridSort:: ?
    HybridSort::sortpart(A, q+1, r); //HybridSort:: ?
    MergeSort::merge(A, p, q, r); //paste MergeSort code below faster?
  }  
}
