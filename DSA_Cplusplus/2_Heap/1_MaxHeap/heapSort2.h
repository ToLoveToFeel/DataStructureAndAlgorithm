#pragma once
#include "MaxHeap.h"

// heapSort2, 借助我们的heapify过程创建堆
// 此时, 创建堆的过程时间复杂度为O(n), 将所有元素依次从堆中取出来, 实践复杂度为O(nlogn)
// 堆排序的总体时间复杂度依然是O(nlogn), 但是比上述heapSort1性能更优, 因为创建堆的性能更优
template<typename T>
void heapSort2(T arr[], int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);

	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxHeap.extractMax();
}
