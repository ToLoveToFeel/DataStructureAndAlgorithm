#pragma once
#include "IndexMaxHeap2.h"

// 使用最大索引堆进行堆排序, 来验证我们的最大索引堆的正确性
// 最大索引堆的主要作用不是用于排序, 我们在这里使用排序只是为了验证我们的最大索引堆实现的正确性
// 在后续的图论中, 无论是最小生成树算法, 还是最短路径算法, 我们都需要使用索引堆进行优化:)
template<typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n) {
	//IndexMaxHeap1<T> indexMaxHeap = IndexMaxHeap1<T>(n);
	IndexMaxHeap2<T> indexMaxHeap = IndexMaxHeap2<T>(n);

	for (int i = 0; i < n; i++)
		indexMaxHeap.insert(i, arr[i]);

	assert(indexMaxHeap.testIndexes());

	for (int i = n - 1; i >= 0; i--)
		arr[i] = indexMaxHeap.extractMax();
}