#include "SortTestHelper.h"
#include "insertionSort.h"


int main(void) {
	int n = 20000;
	int swapTimes = 1000;
	int* arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
	delete[] arr;

	return 0;
}