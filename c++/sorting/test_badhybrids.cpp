#include <iostream>
#include <algorithm>
#include "BadHybridSorts.hpp"

int main( int argc, char *argv[] )
{
	std::cout << std::endl;
	std::cout << "Testing bad hybrid sort with threshold set to 8..." << std::endl;

	
	// Generate random input sequence with 20 elements and values between 0 and 99.	
	std::cout << std::endl;
	std::cout << "Input Sequence" << std::endl;
	int n = argc > 1 ? argc-1 : 20;
	std::vector<int> sequence(n);	
	if (argc > 1)
	{
		for (int i = 0; i < argc-1; i++)
		{
			sequence[i] = atoi(argv[i+1]);
			std::cout << sequence[i] << " ";
		}
	}
	else
	{
		for (std::size_t i = 0; i < sequence.size(); i++)
		{
			sequence[i] = rand() % 100;
			std::cout << sequence[i] << " ";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<int> reference(n);
	for (std::size_t i = 0; i < sequence.size(); i++)
	{
		reference[i] = sequence[i];
	}
	std::sort(reference.begin(), reference.end());

	
	// Run sorting algorithm.	
	BadHybridSorts::sort(sequence, 8);


	int i = 0;
	bool sorted = true;
	while (sorted && i < sequence.size())
	{
		sorted = reference[i] == sequence[i];
		i++;
	}

	// Print output sequence	
	std::cout << "Output Sequence" << std::endl;
	for (std::size_t i = 0; i < sequence.size(); i++)
	{
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << (sorted ? "Sorting is CORRECT." : "Sorting is INCORRECT.") << std::endl;
	std::cout << std::endl;
	
	
	return 0;
}
