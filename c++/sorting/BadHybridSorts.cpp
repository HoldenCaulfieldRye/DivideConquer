#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "BadHybridSorts.hpp"
#include <iostream>

void BadHybridSorts::sort(std::vector<int> &A, int threshold)
{
  sortpart(A, 0, static_cast<int>(A.size())-1, threshold);
}

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
//use threshold to determine when to use insertion sort vs merge sort.
void BadHybridSorts::sortpart(std::vector<int> &A, int p, int r, threshold)
{ 
  if (r-p+1 <= threshold) { //use insertion sort
    InsertionSort::sortpart(A, p, r);
  }
  else { //use merge sort
    int q = (p+r)/2;
    BadHybridSorts::sortpart(A, p, q, threshold);
    BadHybridSorts::sortpart(A, q+1, r, threshold);
    MergeSort::merge(A, p, q, r);
  }  
}
