#pragma once

#include <iostream>
#include <algorithm>
#include "insertionSort.h"

using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int _partition1(T arr[], int l, int r) {
	// 为了解决数据基本有序退化为O(n^2)的问题
	// 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
	swap(arr[l], arr[rand() % (r - l + 1) + l]);

	T v = arr[l];
	int j = l;
	for (int i = l + 1; i <= r; i++)
		if (arr[i] < v) {
			j++;
			swap(arr[j], arr[i]);
		}

	swap(arr[l], arr[j]);

	return j;

}

// 对arr[l...r]部分进行快速排序
template <typename T>
void _quickSort1(T arr[], int l, int r) {
	if (r - l < 16) {
		insertionSort(arr, l, r);
		return;
	}

	int p = _partition1(arr, l, r);
	_quickSort1(arr, l, p - 1);
	_quickSort1(arr, p + 1, r);
}


template <typename T>
void quickSort1(T arr[], int n) {
	srand(time(NULL));
	_quickSort1(arr, 0, n - 1);
}

// 存在的问题：大量重复元素，每次分的不平衡
