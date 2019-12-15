#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// ���ǵĵ��İ�Union-Find
// ��UF2�Ļ����Ϻϲ�����ʱ ���Ǽ��ϵ�rank(�߶�)
namespace UF4 {
	class UnionFind
	{
	private:
		// ���ǵĵ��İ�Union-Find, ʹ��һ�����鹹��һ��ָ�򸸽ڵ����
		// parent[i]��ʾ��һ��Ԫ����ָ��ĸ��ڵ�
		int* parent;
		int* rank;   // rank[i]��ʾ��iΪ���ļ�������ʾ�����Ĳ���
		int count;	// ���ݸ���

	public:
		UnionFind(int n);
		~UnionFind();

		// ���ҹ���, ����Ԫ��p����Ӧ�ļ��ϱ��
		int find(int p);

		// �鿴Ԫ��p��Ԫ��q�Ƿ�����һ������
		// O(h)���Ӷ�
		bool isConnected(int p, int q);

		// �ϲ�Ԫ��p��Ԫ��q�����ļ���
		// O(h) ���Ӷ�
		void unionElements(int p, int q);

	};

	UnionFind::UnionFind(int  n) {
		count = n;

		parent = new int[n];
		rank = new int[n];
		// ��ʼ��, ÿһ��id[i]ָ���Լ�, û�кϲ���Ԫ��
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}

	}

	UnionFind::~UnionFind() {
		delete[] parent;
		delete[] rank;
	}

	int UnionFind::find(int p) {
		assert(p >= 0 && p < count);

		// ����ȥ��ѯ�Լ��ĸ��׽ڵ�, ֱ��������ڵ�
		// ���ڵ���ص�: parent[p] == p
		while (p != parent[p])
			p = parent[p];
		return p;
	}

	bool UnionFind::isConnected(int p, int q) {
		return find(p) == find(q);
	}

	void UnionFind::unionElements(int p, int q) {
		int pRoot = find(p);
		int qRoot = find(q);

		if (pRoot == qRoot)
			return;

		// ��������Ԫ����������Ԫ�ظ�����ͬ�жϺϲ�����
		// ��Ԫ�ظ����ٵļ��Ϻϲ���Ԫ�ظ�����ļ�����
		if (rank[pRoot] < rank[qRoot]) {
			parent[pRoot] = qRoot;
		}
		else if (rank[pRoot] > rank[qRoot]) {
			parent[qRoot] = pRoot;
		}
		else { // rank[pRoot] == rank[qRoot]
			parent[pRoot] = qRoot;
			rank[qRoot] += 1;
		}

	}
}
