#pragma once

#include <iostream>
#include <algorithm>
#include "insertionSort.h"

using namespace std;

// ��arr[l...r]���ֽ���partition����
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int _partition1(T arr[], int l, int r) {
	// Ϊ�˽�����ݻ��������˻�ΪO(n^2)������
	// �����arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
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

// ��arr[l...r]���ֽ��п�������
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

// ���ڵ����⣺�����ظ�Ԫ�أ�ÿ�ηֵĲ�ƽ��
