#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

// 二分查找法,在有序数组arr中,查找target
// 如果找到target,返回相应的索引index
// 如果没有找到target,返回-1
template<typename T>
int binarySearch(T arr[], int n, T target) {
	// 在arr[l...r]之中查找target
	int l = 0, r = n - 1;
	while (l <= r) {
		// 防止极端情况下的整形溢出，使用下面的逻辑求出mid
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


// 用递归的方式写二分查找法
template<typename T>
int __binarySearch2(T arr[], int l, int r, T target) {
	if (l > r)
		return -1;

	// 防止极端情况下的整形溢出，使用下面的逻辑求出mid
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
