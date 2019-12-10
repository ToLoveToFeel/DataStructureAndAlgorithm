#include "SortTestHelper.h"


int main(void) {
	int n = 20000;
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	delete[] arr;

	return 0;
}