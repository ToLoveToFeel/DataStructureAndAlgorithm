#pragma once

#include <iostream>
#include <algorithm>
#include "insertionSort.h"

using namespace std;

// ��arr[l...r]���ֽ���partition����
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int _partition2Way(T arr[], int l, int r) {
	// Ϊ�˽�����ݻ��������˻�ΪO(n^2)������
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	
	// arr[l+1...i) <= v; arr(j...r] >= v
	int i = l + 1;
	int j = r;
	while (true)
	{
		// ע������ı߽�, arr[i] < v, ������arr[i] <= v
		// ˼��һ��Ϊʲô?
		while (i <= r && arr[i] < v) i++;

		// ע������ı߽�, arr[j] > v, ������arr[j] >= v
		// ˼��һ��Ϊʲô?
		while (j >= l + 1 && arr[j] > v) j--;

		// ��������������߽���趨, �е�ͬѧ�ڿγ̵��ʴ����кܺõĻش�:)
		// ��ҿ��Բο�: http://coding.imooc.com/learn/questiondetail/4920.html

		if (i > j)
			break;

		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	swap(arr[l], arr[j]);

	return j;

}

// ��arr[l...r]���ֽ��п�������
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

