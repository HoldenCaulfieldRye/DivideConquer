#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_

#include <vector>

class MergeSort
{
public:
	
  static void sort(std::vector<int> &A);

  static void sortpart(std::vector<int> &A, int p, int r);

  static void merge(std::vector<int> &A, int p, int q, int r);

  static void mergefast(std::vector<int> &A, int p, int q, int r);

};

#endif /*MERGESORT_HPP_*/
