#pragma once
#pragma once


#include <iostream>
#include "insertionSort.h"

using namespace std;


// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
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



// ʹ���Ż��Ĺ鲢�����㷨, ��arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSort2(T arr[], int l, int r) {

	// �Ż�2: ����С��ģ����, ʹ�ò�������
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int mid = (r - l) / 2 + l;
	__mergeSort2(arr, l, mid);
	__mergeSort2(arr, mid + 1, r);

	// �Ż�1: ����arr[mid] <= arr[mid+1]�����,������merge
	// ���ڽ������������ǳ���Ч,���Ƕ���һ�����,��һ����������ʧ
	if (arr[mid] > arr[mid + 1])
		__merge2(arr, l, mid, r);
}


template<typename T>
void mergeSort2(T arr[], int n) {
	__mergeSort2(arr, 0, n - 1);
}

