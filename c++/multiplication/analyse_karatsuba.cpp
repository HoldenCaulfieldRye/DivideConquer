#include <iostream>
#include <fstream>
#include <vector>
#include <sys/time.h>
#include "Helper.hpp"
#include "KaratsubaMultiplication.hpp"

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
	std::ifstream datfile("multiplication.dat", std::ios::in | std::ios::binary);

	if(datfile)
	{
		datfile.seekg(0, datfile.end);
		int length = static_cast<int>(datfile.tellg());
		datfile.seekg(0, datfile.beg);

		std::vector<int> data(length / 4);
		datfile.read(reinterpret_cast<char*>(&data[0]), static_cast<std::streamsize>(length));
		datfile.close();

		int numbers_per_type = 1000;
		int number_types = static_cast<int>(data.size()) / numbers_per_type;

		std::cout << std::endl;
		std::cout << "Analysing karatsuba multiplication..." << std::endl;

		std::cout << std::endl;
		std::cout << "Performing 1 million multiplications..." << std::endl;
		std::vector<long long> runningtime(number_types);
		for (int d = 0; d < number_types; d++)
		{
			long long digits = Helper::digits(data[d * numbers_per_type]);
			std::cout << std::endl;
			std::cout << "...on " << digits << "-digit numbers...";
			runningtime[d] = microseconds();
			for (int i = 0; i < numbers_per_type; i++)
			{
				for (int j = 0; j < numbers_per_type; j++)
				{
					long long x = data[d * numbers_per_type + i];
					long long y = data[d * numbers_per_type + j];
					long long z = KaratsubaMultiplication::multiply(x, y);
				}
			}
			runningtime[d] = microseconds() - runningtime[d];
			std::cout << "took " << runningtime[d] << " microseconds." << std::endl;
		}
		
		std::ofstream resfile;
		resfile.open( "timings_karatsuba.txt" );
		resfile << "# karatsuba multiplication running time\n"; 
		resfile << "# n \tmicroseconds\n"; 
		for (int d = 0; d < number_types; d++)
		{
			long long digits = Helper::digits(data[d * numbers_per_type]);
			char buffer[256];
			sprintf(buffer, "%04d", static_cast<int>(digits));
			std::string el(buffer);
			resfile << el << "\t" << runningtime[d] << "\n";
		}
		resfile.close();			

		std::cout << std::endl;
		std::cout << "Done. Results saved in timings_karatsuba.txt." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Error: Cannot find data file multiplication.dat." << std::endl;
		std::cout << std::endl;
	}
	
	return 0;
}
