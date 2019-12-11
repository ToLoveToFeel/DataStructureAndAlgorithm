#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

// ���ֲ��ҷ�,����������arr��,����target
// ����ҵ�target,������Ӧ������index
// ���û���ҵ�target,����-1
template<typename T>
int binarySearch(T arr[], int n, T target) {
	// ��arr[l...r]֮�в���target
	int l = 0, r = n - 1;
	while (l <= r) {
		// ��ֹ��������µ����������ʹ��������߼����mid
		int mid = (r - l) / 2 + l;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			r = mid - 1;
		else
			l = mid + 1;
	}

	return -1;
}


// �õݹ�ķ�ʽд���ֲ��ҷ�
template<typename T>
int __binarySearch2(T arr[], int l, int r, T target) {
	if (l > r)
		return -1;

	// ��ֹ��������µ����������ʹ��������߼����mid
	int mid = (r - l) / 2 + l;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		__binarySearch2(arr, l, mid - 1, target);
	else
		__binarySearch2(arr, mid + 1, r, target);
}

template<typename T>
int binarySearch2(T arr[], int n, T target) {

	return __binarySearch2(arr, 0, n - 1, target);
}
