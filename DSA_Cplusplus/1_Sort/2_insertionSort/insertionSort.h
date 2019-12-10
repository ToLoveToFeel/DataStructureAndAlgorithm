#pragma once

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {
	for (int i = 1; i < n; i++)
	{
		T element = arr[i];
		int j;
		for (j = i; j > 0 && arr[j - 1] > element; j--)
			arr[j] = arr[j - 1];
		arr[j] = element;
	}
}