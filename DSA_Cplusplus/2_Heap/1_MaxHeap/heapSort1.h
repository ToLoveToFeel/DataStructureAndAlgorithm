#pragma once
#include "MaxHeap.h"

// heapSort1, �����е�Ԫ��������ӵ�����, �ڽ�����Ԫ�شӶ�������ȡ����, �����������
// �����Ǵ����ѵĹ���, ���ǴӶ�������ȡ��Ԫ�صĹ���, ʱ�临�ӶȾ�ΪO(nlogn)
// ���������������ʱ�临�Ӷ�ΪO(nlogn)
template <typename T>
void heapSort1(T arr[], int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(n);

	for (int i = 0; i < n; i++)
		maxHeap.insert(arr[i]);

	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxHeap.extractMax();
}



