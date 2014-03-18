// #ifndef HYBRIDSORT_HPP_
// #define HYBRIDSORT_HPP_

// #include <vector>

// class HybridSort
// {
// public:
	
// 	static void sort(std::vector<int> &A);

// 	static void sortpart(std::vector<int> &A, int p, int r);
// };

// #endif /*HYBRIDSORT_HPP_*/

#ifndef HYBRIDSORT_HPP_
#define HYBRIDSORT_HPP_

#include <vector>

class HybridSort
{
public:

	static void sort(std::vector<int> &A);

	static void sortpart(std::vector<int> &A, int p, int r);
};

#endif /*HYBRIDSORT_HPP_*/
