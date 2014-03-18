#ifndef BADHYBRIDSORTS_HPP_
#define BADHYBRIDSORTS_HPP_

#include <vector>

class LgihtSorts
{
public:
	
  static void sort(std::vector<int> &A, int threshold);

  static void sortpart(std::vector<int> &A, int p, int r);
};

#endif /*BADHYBRIDSORTS_HPP_*/
