#pragma once

using namespace std;

template<typename T>
void insertionSort(T arr[], int l, int r) {
	for (int i = l + 1; i <= r; i++)
	{
		T element = arr[i];
		int j;
		for (j = i; j > l && arr[j - 1] > element; j--)
			arr[j] = arr[j - 1];
		arr[j] = element;
	}
}