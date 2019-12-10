#pragma once
#pragma once


#include <iostream>
#include "insertionSort.h"

using namespace std;


// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void __merge2(T arr[], int l, int mid, int r) {
	//T aux[r - l + 1];
	T* aux = new T[r - l + 1];

	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] > aux[j - l])
		{
			arr[k] = aux[j - l];
			j++;
		}
		else
		{
			arr[k] = aux[i - l];
			i++;
		}
	}

	delete[] aux;
}



// 使用优化的归并排序算法, 对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort2(T arr[], int l, int r) {

	// 优化2: 对于小规模数组, 使用插入排序
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int mid = (r - l) / 2 + l;
	__mergeSort2(arr, l, mid);
	__mergeSort2(arr, mid + 1, r);

	// 优化1: 对于arr[mid] <= arr[mid+1]的情况,不进行merge
	// 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
	if (arr[mid] > arr[mid + 1])
		__merge2(arr, l, mid, r);
}


template<typename T>
void mergeSort2(T arr[], int n) {
	__mergeSort2(arr, 0, n - 1);
}

