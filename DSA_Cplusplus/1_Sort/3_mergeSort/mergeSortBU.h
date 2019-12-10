#pragma once

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void __merge(T arr[], int l, int mid, int r) {
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


// 使用自底向上的归并排序算法
template <typename T>
void mergeSortBU(T arr[], int n) {
	// Merge Sort Bottom Up 无优化版本
	//for (int sz = 1; sz < n; sz += sz) {
	//	for (int i = 0; i + sz < n; i += sz + sz) {
	//		__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
	//	}
	//}


	// Merge Sort Bottom Up 优化
	// 对于小数组, 使用插入排序优化
	for (int i = 0; i < n; i += 16)
		insertionSort(arr, i, min(i + 15, n - 1));

	for (int sz = 16; sz < n; sz += sz) {
		for (int i = 0; i + sz < n; i += sz + sz) {
			// 对于arr[mid] <= arr[mid+1]的情况,不进行merge
			if (arr[i + sz - 1] > arr[i + sz])
				__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}
	}

}
