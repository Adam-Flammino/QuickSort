// QuickSort.cpp
// Adam Flammino  SDEV 345, 7/7
// Uses quick sort to sort a vector of 250 random ints
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include  <vector>

class Sorter
{
private:
	std::vector<double>workspace;
	int numElements = 0;
	int partition = 0;
public:
	// Inserts elements into vector
	void insert(double value){ 
		workspace.push_back(value);
		numElements++;
	}
	// Prints contents of vector
	void print()
	{
		std::cout << "Contents:\n";
		for(int i = 0; i < numElements; i++)
		{
			std::cout << workspace[i] << "\t";
		}
		std::cout << std::endl;
	}
	// Sorts vector
	void quicksort()
	{
		recQuickSort(0, numElements - 1); // Recursive quicksort call
	}

	// Recurisive quicksort
	void recQuickSort(int left, int right)
	{
		if (!(right - left <= 0)) // Stop when list is sorted
		{
			double pivot = workspace[right];
			partition = partitionIt(left, right, pivot);
			recQuickSort(left, partition - 1); // sort left
			recQuickSort(partition + 1, right); // sort right
		}
	}
	// Gets correct values on each side of pivot
	int partitionIt(int left, int right, double pivot)
	{
		int leftMark = left - 1; 
		int rightMark = right;
		while (true) {
			while (workspace[++leftMark] < pivot) // get larger item
				;
			while (workspace[--rightMark] > pivot && rightMark > 0) // get smaller item
				;
			if (leftMark >= rightMark) { // stop when markers cross
				break;
			}
				swap(leftMark, rightMark);
		}
		swap (leftMark, right); // Place pivot back where it belongs
		return leftMark;
	}
	// Swap two elements
	void swap (int l, int r)
	{
		double temp = workspace[l];
		workspace[l] = workspace[r];
		workspace[r] = temp;
	}
};



int main()
{
	final: int MAX_SIZE = 250;
	int n;
	srand(time(nullptr)); // random seed
	Sorter s;
	for(int i = 0; i < MAX_SIZE; i++)
	{
		n = rand() % 1001;
		s.insert(n);
	}
	s.print();
	clock_t start = clock();
	s.quicksort();
	clock_t end = clock();
	std::cout << "Sorted ";
	s.print();
	std::cout << "This array took " << end - start << " ticks(s) to sort." << 
		" Average runtime is O(n log n). Worst case runtime is O(n^2)\n";
    return 0;
}

