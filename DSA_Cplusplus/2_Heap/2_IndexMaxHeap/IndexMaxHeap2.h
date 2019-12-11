#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

// 最大索引堆
template <typename Item>
class IndexMaxHeap2 {

private:
	Item* data;		// 最大索引堆中的数据
	int* indexes;		// 第k大的数据是data[indexes[k]]
	int* reverse;		// data[i]从大到小的排名是reverse[i]
	// indexes[k] = i  索引i的数据<-->排名k
	// reverse[i] = k  排名k<-->索引i的数据

	int count;		// 堆中数据的个数
	int capacity;		// 堆的容量

	// 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
	void shiftUp(int k) {

		while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
			swap(indexes[k / 2], indexes[k]);
			reverse[indexes[k / 2]] = k / 2;
			reverse[indexes[k]] = k;
			k /= 2;
		}
	}

	// 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
	void shiftDown(int k) {

		while (2 * k <= count) {
			int j = 2 * k;
			if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
				j += 1;

			if (data[indexes[k]] >= data[indexes[j]])
				break;

			swap(indexes[k], indexes[j]);
			reverse[indexes[k]] = k;
			reverse[indexes[j]] = j;
			k = j;
		}
	}

public:
	// 构造函数, 构造一个空的索引堆, 可容纳capacity个元素
	IndexMaxHeap2(int capacity) {
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		reverse = new int[capacity + 1];
		for (int i = 0; i <= capacity; i++)
			reverse[i] = 0;

		this->count = 0;
		this->capacity = capacity;
	}

	// 析构函数
	~IndexMaxHeap2() {
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}

	// 返回索引堆中的元素个数
	int size() {
		return count;
	}

	// 返回一个布尔值, 表示索引堆中是否为空
	bool isEmpty() {
		return 0 == count;
	}

	// 看索引i所在的位置是否存在元素
	bool contain(int i) {
		assert(i + 1 >= 1 && i + 1 <= capacity);
		return reverse[i + 1] != 0;
	}

	// 向最大索引堆中插入一个新的元素, 新元素的索引为i, 元素为item
	// 传入的i对用户而言,是从0索引的
	void insert(int i, Item item) {
		assert(count + 1 <= capacity);
		
		// 再插入一个新元素前,还需要保证索引i所在的位置是没有元素的。
		assert(!contain(i));

		i += 1;
		data[i] = item;
		indexes[count + 1] = i;
		reverse[i] = count + 1;
		count++;

		shiftUp(count);
	}

	// 从最大索引堆中取出堆顶元素, 即索引堆中所存储的最大数据
	Item extractMax() {
		assert(count > 0);

		Item ret = data[indexes[1]];
		swap(indexes[1], indexes[count]);
		reverse[indexes[count]] = 0;
		count--;

		if (count) {
			reverse[indexes[1]] = 1;
			shiftDown(1);
		}

		return ret;
	}

	// 从最大索引堆中取出堆顶元素的索引
	int extractMaxIndex() {
		assert(count > 0);

		int ret = indexes[1] - 1;
		swap(indexes[1], indexes[count]);
		reverse[indexes[count]] = 0;
		count--;

		if (count) {
			reverse[indexes[1]] = 1;
			shiftDown(1);
		}

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
		assert(contain(i));
		return data[i + 1];
	}

	// 将最大索引堆中索引为i的元素修改为newItem
	void change(int i, Item newItem) {

		assert(contain(i));
		i += 1;
		data[i] = newItem;

		// 找到indexes[j] = i, j表示data[i]在堆中的位置
		// 之后shiftUp(j), 再shiftDown(j)
//        for( int j = 1 ; j <= count ; j ++ )
//            if( indexes[j] == i ){
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }

		// 有了 reverse 之后,
		// 我们可以非常简单的通过reverse直接定位索引i在indexes中的位置
		shiftUp(reverse[i]);
		shiftDown(reverse[i]);
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

