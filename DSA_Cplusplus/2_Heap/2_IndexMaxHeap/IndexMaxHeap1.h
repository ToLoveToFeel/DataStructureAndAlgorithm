#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

// 最大索引堆
template <typename Item>
class IndexMaxHeap1 {

private:
	Item* data;		// 最大索引堆中的数据
	int* indexes;		// 最大索引堆中的索引，indexes[1]=10表示的含义是最大的数据是data[indexes[1]] = data[10]
					// 第k大的数据是data[indexes[k]]

	int count;		// 堆中数据的个数
	int capacity;		// 堆的容量

	// 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
	void shiftUp(int k) {
		while (k > 1 && data[indexes[k/2]] < data[indexes[k]])
		{
			swap(indexes[k / 2], indexes[k]);
			k /= 2;
		}
	}

	// 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
	void shiftDown(int k) {
		while (2*k <= count)
		{
			int j = 2 * k;
			if (j + 1 < count && data[indexes[j + 1]] > data[indexes[j]])
				j++;

			if (data[indexes[k]] > data[indexes[j]])
				break;
			swap(indexes[k], indexes[j]);

			k = j;
		}
	}

public:
	// 构造函数, 构造一个空的索引堆, 可容纳capacity个元素
	IndexMaxHeap1(int capacity) {
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];

		this->count = 0;
		this->capacity = capacity;
	}

	// 析构函数
	~IndexMaxHeap1() {
		delete[] data;
		delete[] indexes;
	}

	// 返回索引堆中的元素个数
	int size() {
		return count;
	}

	// 返回一个布尔值, 表示索引堆中是否为空
	bool isEmpty() {
		return 0 == count;
	}

	// 向最大索引堆中插入一个新的元素, 新元素的索引为i, 元素为item
	// 传入的i对用户而言,是从0索引的
	void insert(int i, Item item) {
		assert(count + 1 <= capacity);
		assert(i + 1 >= 1 && i + 1 <= capacity);

		i += 1;
		data[i] = item;
		indexes[count + 1] = i;
		count++;

		shiftUp(count);
	}

	// 从最大索引堆中取出堆顶元素, 即索引堆中所存储的最大数据
	Item extractMax() {
		assert(count > 0);

		Item ret = data[indexes[1]];
		swap(indexes[1], indexes[count]);
		count--;

		shiftDown(1);

		return ret;
	}

	// 从最大索引堆中取出堆顶元素的索引
	int extractMaxIndex() {
		assert(count > 0);

		int ret = indexes[1] - 1;
		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);
		return ret;
	}

	// 获取最大索引堆中的堆顶元素
	Item getMax() {
		assert(count > 0);
		return data[indexes[1]];
	}

	// 获取最大索引堆中的堆顶元素的索引
	int getMaxIndex() {
		assert(count > 0);
		return indexes[1] - 1;
	}

	// 获取最大索引堆中索引为i的元素
	Item getItem(int i) {
		assert(i + 1 >= 1 && i + 1 <= count);		// TODO
		return data[i + 1];
	}

	// 将最大索引堆中索引为i的元素修改为newItem
	void change(int i, Item newItem) {

		i += 1;
		data[i] = newItem;

		// 找到indexes[j] = i, j表示data[i]在堆中的位置
		// 即排名多少(j)的元素索引是i?
		// 之后shiftUp(j), 再shiftDown(j)
		for(int j = 1; j <= count; j++)
			if (indexes[j] == i) {
				shiftUp(j);
				shiftDown(j);
				return;
			}
	}

	// 测试索引堆中的索引数组index
	// 注意:这个测试在向堆中插入元素以后, 不进行extract操作有效
	bool testIndexes() {

		int* copyIndexes = new int[count + 1];

		for (int i = 0; i <= count; i++)
			copyIndexes[i] = indexes[i];

		copyIndexes[0] = 0;
		std::sort(copyIndexes, copyIndexes + count + 1);

		// 在对索引堆中的索引进行排序后, 应该正好是1...count这count个索引
		bool res = true;
		for (int i = 1; i <= count; i++)
			if (copyIndexes[i - 1] + 1 != copyIndexes[i]) {
				res = false;
				break;
			}

		delete[] copyIndexes;

		if (!res) {
			cout << "Error!" << endl;
			return false;
		}

		return true;
	}

};

