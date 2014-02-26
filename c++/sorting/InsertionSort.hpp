#ifndef INSERTIONSORT_HPP_
#define INSERTIONSORT_HPP_

#include <vector>

class InsertionSort
{
public:
	
	static void sort(std::vector<int> &A);

	static void sortpart(std::vector<int> &A, int p, int r);
};

#endif /*INSERTIONSORT_HPP_*/
