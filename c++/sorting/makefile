insertion: InsertionSort.hpp InsertionSort.cpp test_insertion.cpp
	g++ -Wall -g InsertionSort.cpp test_insertion.cpp -o test_insertion

merge: MergeSort.hpp MergeSort.cpp test_merge.cpp
	g++ -Wall -g MergeSort.cpp test_merge.cpp -o test_merge

hybrid: HybridSort.hpp InsertionSort.cpp MergeSort.cpp HybridSort.cpp test_hybrid.cpp
	g++ -Wall -g InsertionSort.cpp MergeSort.cpp HybridSort.cpp test_hybrid.cpp -o test_hybrid

badhybrids: BadHybridSorts.hpp InsertionSort.cpp MergeSort.cpp BadHybridSorts.cpp test_badhybrids.cpp
	g++ -Wall -g InsertionSort.cpp MergeSort.cpp BadHybridSorts.cpp test_badhybrids.cpp -o test_badhybrids

lightsorts: LightSorts.hpp LightSorts.cpp test_lightsorts.cpp
	g++ -Wall -g LightSorts.cpp test_lightsorts.cpp -o test_lightsorts


analyse_insertion: InsertionSort.hpp InsertionSort.cpp analyse_insertion.cpp
	g++ -Wall -g InsertionSort.cpp analyse_insertion.cpp -o analyse_insertion

analyse_merge: MergeSort.hpp MergeSort.cpp analyse_merge.cpp
	g++ -Wall -g MergeSort.cpp analyse_merge.cpp -o analyse_merge

analyse_hybrid: HybridSort.hpp InsertionSort.cpp MergeSort.cpp HybridSort.cpp analyse_hybrid.cpp
	g++ -Wall -g InsertionSort.cpp MergeSort.cpp HybridSort.cpp analyse_hybrid.cpp -o analyse_hybrid
