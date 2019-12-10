#include "SortTestHelper.h"
#include "mergeSort1.h"
#include "mergeSort2.h"
#include "mergeSortBU.h"

int main(void) {

	int n = 1000000;
	int swapTimes = 20;
	//int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort1", mergeSort1, arr1, n);
	SortTestHelper::testSort("Merge Sort2", mergeSort2, arr2, n);
	SortTestHelper::testSort("Merge SortBU", mergeSortBU, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}


