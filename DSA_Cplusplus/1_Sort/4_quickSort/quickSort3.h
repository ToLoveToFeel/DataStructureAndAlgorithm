#pragma once

#include <iostream>
#include <algorithm>
#include "insertionSort.h"

using namespace std;


// �ݹ����·���������㷨
template <typename T>
void _quickSort3Way(T arr[], int l, int r) {
	// ����С��ģ����, ʹ�ò�����������Ż�
	if (r - l < 16) {
		insertionSort(arr, l, r);
		return;
	}

	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	
	int lt = l;			// arr[l+1...lt] < v
	int gt = r + 1;		// arr[gt...r] > v
	int i = l + 1;		// arr[lt+1...i) == v
	while (i < gt)
	{
		if (arr[i] < v)
		{
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else { // arr[i] == v
			i++;
		}
	}

	swap(arr[l], arr[lt]);

	_quickSort3Way(arr, l, lt - 1);
	_quickSort3Way(arr, gt, r);
}


template <typename T>
void quickSort3(T arr[], int n) {
	srand(time(NULL));
	_quickSort3Way(arr, 0, n - 1);
}

