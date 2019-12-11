#include "SortTestHelper.h"
#include "heapSort1.h"
#include "heapSort2.h"
#include "heapSort3.h"


int main(void) {

	int n = 1000000;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Heap Sort1", heapSort1, arr1, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr2, n);
	SortTestHelper::testSort("Heap Sort3", heapSort, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}