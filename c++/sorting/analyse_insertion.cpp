#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <sys/time.h>
#include "InsertionSort.hpp"

unsigned long long microseconds()
{
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv, &tz);
	return tv.tv_sec*1000000 + tv.tv_usec;
}

int main( int argc, char *argv[] )
{
	std::cout << std::endl;
	std::cout << "Reading data for analysis..." << std::endl;
	std::ifstream datfile("sorting.dat", std::ios::in | std::ios::binary);

	if(datfile)
	{
		datfile.seekg(0, datfile.end);
		int length = static_cast<int>(datfile.tellg());
		datfile.seekg(0, datfile.beg);

		std::vector<int> data(length / 4);
		datfile.read(reinterpret_cast<char*>(&data[0]), static_cast<std::streamsize>(length));
		datfile.close();

		int number_tests = 11;
		int numbers_per_sequence = 2048;
		int number_sequences = static_cast<int>(data.size()) / numbers_per_sequence;

		std::cout << std::endl;
		std::cout << "Analysing insertion sort..." << std::endl;

		std::cout << std::endl;
		std::cout << "Performing sort on " << number_sequences << " sequences..." << std::endl;
		std::vector<long long> runningtime(number_tests);
		for (int d = 0; d < number_tests; d++)
		{
			int number_elements = pow(2,(d+1));
			std::vector< std::vector<int> > sequences(number_sequences);
			for (int s = 0; s < number_sequences; s++)
			{
				sequences[s] = std::vector<int>(number_elements);
				for (int e = 0; e < number_elements; e++)
				{
					sequences[s][e] = data[s * numbers_per_sequence + e];
				}
			}
			
			std::cout << std::endl;
			std::cout << "...with " << number_elements << " elements...";
			runningtime[d] = microseconds();
			for (int i = 0; i < number_sequences; i++)
			{
				InsertionSort::sort(sequences[i]);
			}
			runningtime[d] = microseconds() - runningtime[d];
			std::cout << "took " << runningtime[d] << " microseconds." << std::endl;
		}
		
		std::ofstream resfile;
		resfile.open( "timings_insertion.txt" );
		resfile << "# insertion sort running time\n"; 
		resfile << "# n \tmicroseconds\n"; 
		for (std::size_t d = 0; d < number_tests; d++)
		{
			char buffer[256];
			sprintf(buffer, "%04d", static_cast<int>(pow(2,(d+1))));
			std::string el(buffer);
			resfile << el << "\t" << runningtime[d] << "\n";
		}
		resfile.close();

		std::cout << std::endl;
		std::cout << "Done. Results saved in timings_insertion.txt." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Error: Cannot find data file sorting.dat." << std::endl;
		std::cout << std::endl;
	}
	
	return 0;
}
