#include "SortTestHelper.h"
#include "quickSort1.h"
#include "quickSort2.h"
#include "quickSort3.h"

int main(void) {

	int n = 100000;
	int swapTimes = 100;
	//int* arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);

	//SortTestHelper::testSort("quick Sort: ", quickSort1, arr1, n);
	SortTestHelper::testSort("quick Sort: ", quickSort2, arr2, n);
	SortTestHelper::testSort("quick Sort: ", quickSort3, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}