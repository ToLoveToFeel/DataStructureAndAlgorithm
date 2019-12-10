#pragma once


#include <iostream>

using namespace std;


// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename  T>
void __merge1(T arr[], int l, int mid, int r) {
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



// �ݹ�ʹ�ù鲢����,��arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSort1(T arr[], int l, int r) {
	if (l >= r)
		return;

	int mid = (r - l) / 2 + l;
	__mergeSort1(arr, l, mid);
	__mergeSort1(arr, mid + 1, r);
	__merge1(arr, l, mid, r);
}


template<typename T>
void mergeSort1(T arr[], int n) {
	__mergeSort1(arr, 0, n - 1);
}

