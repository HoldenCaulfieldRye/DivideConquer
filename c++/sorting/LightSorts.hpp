#ifndef LIGHTSORTS_HPP_
#define LIGHTSORTS_HPP_

#include <vector>

class LgihtSorts
{
public:
	
  static void lightMergeSort(std::vector<int> &A);
  
  static void lightHybridSort(std::vector<int> &A);

  static void sortpart(std::vector<int> &A, int p, int r);

  static void merge(std::vector<int> &A, int p, int q, int r);

  static void hsortpart(std::vector<int> &A, int p, int r);
};

#endif /*LIGHTSORTS_HPP_*/
