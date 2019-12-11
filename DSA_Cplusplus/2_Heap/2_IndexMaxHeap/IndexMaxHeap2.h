#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

// ���������
template <typename Item>
class IndexMaxHeap2 {

private:
	Item* data;		// ����������е�����
	int* indexes;		// ��k���������data[indexes[k]]
	int* reverse;		// data[i]�Ӵ�С��������reverse[i]
	// indexes[k] = i  ����i������<-->����k
	// reverse[i] = k  ����k<-->����i������

	int count;		// �������ݵĸ���
	int capacity;		// �ѵ�����

	// ��������, ����֮��ıȽϸ���data�Ĵ�С���бȽ�, ��ʵ�ʲ�����������
	void shiftUp(int k) {

		while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
			swap(indexes[k / 2], indexes[k]);
			reverse[indexes[k / 2]] = k / 2;
			reverse[indexes[k]] = k;
			k /= 2;
		}
	}

	// ��������, ����֮��ıȽϸ���data�Ĵ�С���бȽ�, ��ʵ�ʲ�����������
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
	// ���캯��, ����һ���յ�������, ������capacity��Ԫ��
	IndexMaxHeap2(int capacity) {
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		reverse = new int[capacity + 1];
		for (int i = 0; i <= capacity; i++)
			reverse[i] = 0;

		this->count = 0;
		this->capacity = capacity;
	}

	// ��������
	~IndexMaxHeap2() {
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}

	// �����������е�Ԫ�ظ���
	int size() {
		return count;
	}

	// ����һ������ֵ, ��ʾ���������Ƿ�Ϊ��
	bool isEmpty() {
		return 0 == count;
	}

	// ������i���ڵ�λ���Ƿ����Ԫ��
	bool contain(int i) {
		assert(i + 1 >= 1 && i + 1 <= capacity);
		return reverse[i + 1] != 0;
	}

	// ������������в���һ���µ�Ԫ��, ��Ԫ�ص�����Ϊi, Ԫ��Ϊitem
	// �����i���û�����,�Ǵ�0������
	void insert(int i, Item item) {
		assert(count + 1 <= capacity);
		
		// �ٲ���һ����Ԫ��ǰ,����Ҫ��֤����i���ڵ�λ����û��Ԫ�صġ�
		assert(!contain(i));

		i += 1;
		data[i] = item;
		indexes[count + 1] = i;
		reverse[i] = count + 1;
		count++;

		shiftUp(count);
	}

	// �������������ȡ���Ѷ�Ԫ��, �������������洢���������
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

	// �������������ȡ���Ѷ�Ԫ�ص�����
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

	// ��ȡ����������еĶѶ�Ԫ��
	Item getMax() {
		assert(count > 0);
		return data[indexes[1]];
	}

	// ��ȡ����������еĶѶ�Ԫ�ص�����
	int getMaxIndex() {
		assert(count > 0);
		return indexes[1] - 1;
	}

	// ��ȡ���������������Ϊi��Ԫ��
	Item getItem(int i) {
		assert(contain(i));
		return data[i + 1];
	}

	// �����������������Ϊi��Ԫ���޸�ΪnewItem
	void change(int i, Item newItem) {

		assert(contain(i));
		i += 1;
		data[i] = newItem;

		// �ҵ�indexes[j] = i, j��ʾdata[i]�ڶ��е�λ��
		// ֮��shiftUp(j), ��shiftDown(j)
//        for( int j = 1 ; j <= count ; j ++ )
//            if( indexes[j] == i ){
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }

		// ���� reverse ֮��,
		// ���ǿ��Էǳ��򵥵�ͨ��reverseֱ�Ӷ�λ����i��indexes�е�λ��
		shiftUp(reverse[i]);
		shiftDown(reverse[i]);
	}

	// �����������е���������index
	// ע��:�������������в���Ԫ���Ժ�, ������extract������Ч
	bool testIndexes() {

		int* copyIndexes = new int[count + 1];

		for (int i = 0; i <= count; i++)
			copyIndexes[i] = indexes[i];

		copyIndexes[0] = 0;
		std::sort(copyIndexes, copyIndexes + count + 1);

		// �ڶ��������е��������������, Ӧ��������1...count��count������
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

