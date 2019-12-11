#pragma once

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template<typename Item>
class MaxHeap {

private:
	Item* data;
	int count;		// 堆中数据的个数
	int capacity;		// 堆的容量

	void shiftUp(int k) {
		while (k > 1 && data[k/2] < data[k])
		{
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}

	void shiftDown(int k) {
		while (2*k <= count)
		{
			int j = 2 * k;
			if (j + 1 <= count && data[j + 1] > data[j])
				j++;
			if (data[k] >= data[j])
				break;
			swap(data[k], data[j]);
			k = j;
		}
	}

public:
	// 构造函数, 构造一个空堆, 可容纳capacity个元素
	MaxHeap(int capacity) {
		data = new Item[capacity + 1];
		this->capacity = capacity;
		count = 0;
	}

	// 构造函数, 通过一个给定数组创建一个最大堆
	// 该构造堆的过程, 时间复杂度为O(n)
	MaxHeap(Item arr[], int n) {
		data = new Item[n + 1];
		this->capacity = n;
		
		for (int i = 1; i < n + 1; i++)
			data[i] = arr[i - 1];
		this->count = n;

		for (int i = count / 2; i >= 1; i--)
			shiftDown(i);
	}

	// 析构函数
	~MaxHeap() {
		delete[] data;
	}

	// 返回堆中的元素个数
	int size() {
		return count;
	}

	// 返回一个布尔值, 表示堆中是否为空
	bool isEmpty() {
		return 0 == count;
	}

	// 像最大堆中插入一个新的元素 item
	void insert(Item item) {
		assert(count + 1 <= capacity);
		count++;
		data[count] = item;
		shiftUp(count);
	}

	// 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
	Item extractMax() {
		assert(count > 0);
		Item ret = data[1];
		swap(data[1], data[count]);
		count--;
		shiftDown(1);

		return ret;
	}

	// 获取最大堆中的堆顶元素
	Item getMax() {
		assert(count > 0);
		return data[1];
	}

};



