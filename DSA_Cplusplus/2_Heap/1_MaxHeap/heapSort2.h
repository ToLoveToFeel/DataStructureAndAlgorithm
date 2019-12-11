#pragma once
#include "MaxHeap.h"

// heapSort2, �������ǵ�heapify���̴�����
// ��ʱ, �����ѵĹ���ʱ�临�Ӷ�ΪO(n), ������Ԫ�����δӶ���ȡ����, ʵ�����Ӷ�ΪO(nlogn)
// �����������ʱ�临�Ӷ���Ȼ��O(nlogn), ���Ǳ�����heapSort1���ܸ���, ��Ϊ�����ѵ����ܸ���
template<typename T>
void heapSort2(T arr[], int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);

	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxHeap.extractMax();
}
