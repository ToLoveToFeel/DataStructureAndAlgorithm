#include "SortTestHelper.h"
#include "heapSortUsingIndexMaxHeap.h"

int main(void) {

	int n = 1000000;

	int* arr = SortTestHelper::generateRandomArray(n, 0, n);

	SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap, arr, n);

	delete[] arr;

	return 0;
}