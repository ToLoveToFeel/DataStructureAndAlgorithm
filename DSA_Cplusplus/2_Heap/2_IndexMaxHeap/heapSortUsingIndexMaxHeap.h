#pragma once
#include "IndexMaxHeap2.h"

// ʹ����������ѽ��ж�����, ����֤���ǵ���������ѵ���ȷ��
// ��������ѵ���Ҫ���ò�����������, ����������ʹ������ֻ��Ϊ����֤���ǵ����������ʵ�ֵ���ȷ��
// �ں�����ͼ����, ��������С�������㷨, �������·���㷨, ���Ƕ���Ҫʹ�������ѽ����Ż�:)
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