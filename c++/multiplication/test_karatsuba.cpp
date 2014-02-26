#include <iostream>
#include <stdlib.h>
#include "KaratsubaMultiplication.hpp"

int main( int argc, char *argv[] )
{
	std::cout << std::endl;
	std::cout << "Testing karatsuba multiplication..." << std::endl;

	
	// Generate two numbers.
	std::cout << std::endl;
	std::cout << "Input" << std::endl;
	
	long long x = 5678;
	long long y = 1234;
	if (argc == 3)
	{
		x = atol(argv[1]);
		y = atol(argv[2]);
	}
	std::cout << "x: " << x << " y: " << y << std::endl;
	std::cout << std::endl;


	// Run multiplication algorithm.
	long long z = KaratsubaMultiplication::multiply(x, y);

	
	// Print output result
	std::cout << "Output" << std::endl;
	std::cout << "x * y = z: " << z;
	if (z == x * y)
	{
		std::cout << " is CORRECT." << std::endl;
	}
	else
	{
		std::cout << " is INCORRECT." << std::endl;
		std::cout << std::endl;
		std::cout << "Solution should be " << (x * y) << ". Difference is " << (z - (x * y)) << "." << std::endl;
	}
	std::cout << std::endl;
	
	
	return 0;
}
