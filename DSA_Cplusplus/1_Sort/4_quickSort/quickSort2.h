#pragma once

#include <iostream>
#include <algorithm>
#include "insertionSort.h"

using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int _partition2Way(T arr[], int l, int r) {
	// 为了解决数据基本有序退化为O(n^2)的问题
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	
	// arr[l+1...i) <= v; arr(j...r] >= v
	int i = l + 1;
	int j = r;
	while (true)
	{
		// 注意这里的边界, arr[i] < v, 不能是arr[i] <= v
		// 思考一下为什么?
		while (i <= r && arr[i] < v) i++;

		// 注意这里的边界, arr[j] > v, 不能是arr[j] >= v
		// 思考一下为什么?
		while (j >= l + 1 && arr[j] > v) j--;

		// 对于上面的两个边界的设定, 有的同学在课程的问答区有很好的回答:)
		// 大家可以参考: http://coding.imooc.com/learn/questiondetail/4920.html

		if (i > j)
			break;

		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	swap(arr[l], arr[j]);

	return j;

}

// 对arr[l...r]部分进行快速排序
template <typename T>
void _quickSort2(T arr[], int l, int r) {
	if (r - l < 16) {
		insertionSort(arr, l, r);
		return;
	}

	int p = _partition2Way(arr, l, r);
	_quickSort2(arr, l, p - 1);
	_quickSort2(arr, p + 1, r);
}


template <typename T>
void quickSort2(T arr[], int n) {
	srand(time(NULL));
	_quickSort2(arr, 0, n - 1);
}

