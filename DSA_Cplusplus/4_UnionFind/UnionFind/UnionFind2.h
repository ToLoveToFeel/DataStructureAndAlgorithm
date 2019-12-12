#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// ���ǵĵڶ���Union-Find
// ˼·��UF1��ȫ��ͬ
namespace UF2 {
	class UnionFind
	{
	private:
		// ���ǵĵڶ���Union-Find, ʹ��һ�����鹹��һ��ָ�򸸽ڵ����
		// parent[i]��ʾ��һ��Ԫ����ָ��ĸ��ڵ�
		int* parent;
		int count;	// ���ݸ���

	public:
		UnionFind(int n);
		~UnionFind();

		// ���ҹ���, ����Ԫ��p����Ӧ�ļ��ϱ��
		int find(int p);

		// �鿴Ԫ��p��Ԫ��q�Ƿ�����һ������
		// O(1)���Ӷ�
		bool isConnected(int p, int q);

		// �ϲ�Ԫ��p��Ԫ��q�����ļ���
		// O(n) ���Ӷ�
		void unionElements(int p, int q);

	};

	UnionFind::UnionFind(int  n) {
		count = n;

		parent = new int[n];
		// ��ʼ��, ÿһ��id[i]ָ���Լ�, û�кϲ���Ԫ��
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	UnionFind::~UnionFind() {
		delete[] parent;
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

		parent[pRoot] = qRoot;
	}
}
