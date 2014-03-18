#include "LightSorts.hpp"
#include <iostream>

void LightSorts::lightMergeSort(std::vector<int> &A)
{
	sortpart(A, 0, static_cast<int>(A.size())-1);
}

/*with these light data structures, it is optimal for hybrid
  sort to never use insertion sort, and instead to run pure 
  merge sort throughout.*/
void LightSorts::lightHybridSort(std::vector<int> &A)
{
	hsortpart(A, 0, static_cast<int>(A.size())-1);
}

/******************************************************/
/*************** COMPLETE THIS FUNCTION ***************/
/******************************************************/
void LightSorts::sortpart(std::vector<int> &A, int p, int r)
{
  if (p < r) {
    int q = (p+r)/2;
    sortpart(A, p, q);
    sortpart(A, q+1, r);
    merge(A, p, q, r);
  }
}

void LightSorts::merge(std::vector<int> &A, int p, int q, int r)
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


void LightSorts::hsortpart(std::vector<int> &A, int p, int r)
{
  /*if subarray of size 2, don't copy it all. Just store an entry as temp if it needs to be flipped, and do nothing otherwise.*/
  if (r-p+1 <= 2) {
    if (A[p] > A[r]) {
      int temp = A[p];
      A[p] = A[r];
      A[r] = temp;
    }
  }
  else {
    int q = (p+r)/2;
    HybridSort::hsortpart(A, p, q);
    HybridSort::hsortpart(A, q+1, r);
    LightSorts::merge(A, p, q, r);
  }  
}
