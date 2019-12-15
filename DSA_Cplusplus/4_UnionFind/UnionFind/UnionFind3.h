#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// ���ǵĵ�����Union-Find
// ��UF2�Ļ����Ϻϲ�����ʱ ���Ǽ��ϵĴ�С
namespace UF3 {
	class UnionFind
	{
	private:
		// ���ǵĵ�����Union-Find, ʹ��һ�����鹹��һ��ָ�򸸽ڵ����
		// parent[i]��ʾ��һ��Ԫ����ָ��ĸ��ڵ�
		int* parent;
		int* sz;     // sz[i]��ʾ��iΪ���ļ�����Ԫ�ظ���
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
		sz = new int[n];
		// ��ʼ��, ÿһ��id[i]ָ���Լ�, û�кϲ���Ԫ��
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			sz[i] = 1;
		}
			
	}

	UnionFind::~UnionFind() {
		delete[] parent;
		delete[] sz;
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
		if (sz[pRoot] < sz[qRoot]) {
			parent[pRoot] = qRoot;
			sz[qRoot] += sz[pRoot];
		}
		else {
			parent[qRoot] = pRoot;
			sz[pRoot] += sz[qRoot];
		}
			
	}
}
